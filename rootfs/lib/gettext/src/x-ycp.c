/* xgettext YCP backend.
   Copyright (C) 2001-2002 Free Software Foundation, Inc.

   This file was written by Bruno Haible <haible@clisp.cons.org>, 2001.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "message.h"
#include "x-ycp.h"
#include "xgettext.h"
#include "error.h"
#include "xmalloc.h"
#include "exit.h"
#include "gettext.h"

#define _(s) gettext(s)


/* The YCP syntax is defined in libycp/doc/syntax.html.
   See also libycp/src/scanner.ll.  */

enum token_type_ty
{
  token_type_eof,
  token_type_lparen,		/* ( */
  token_type_rparen,		/* ) */
  token_type_comma,		/* , */
  token_type_i18n,		/* _( */
  token_type_string_literal,	/* "abc" */
  token_type_symbol,		/* symbol, number */
  token_type_other		/* misc. operator */
};
typedef enum token_type_ty token_type_ty;

typedef struct token_ty token_ty;
struct token_ty
{
  token_type_ty type;
  char *string;		/* for token_type_string_literal, token_type_symbol */
  int line_number;
};


/* Real filename, used in error messages about the input file.  */
static const char *real_file_name;

/* Logical filename and line number, used to label the extracted messages.  */
static char *logical_file_name;
static int line_number;
static int char_in_line;

/* The input file stream.  */
static FILE *fp;

/* These are for tracking whether comments count as immediately before
   keyword.  */
static int last_comment_line;
static int last_non_comment_line;


/* Prototypes for local functions.  Needed to ensure compiler checking of
   function argument counts despite of K&R C function definition syntax.  */
static int phase1_getc PARAMS ((void));
static void phase1_ungetc PARAMS ((int c));
static int phase2_getc PARAMS ((void));
static void phase2_ungetc PARAMS ((int c));
static int phase7_getc PARAMS ((void));
static void x_ycp_lex PARAMS ((token_ty *tp));


/* 1. line_number handling.  */

static int
phase1_getc ()
{
  int c = getc (fp);

  if (c == EOF)
    {
      if (ferror (fp))
	error (EXIT_FAILURE, errno, _("error while reading \"%s\""),
	       real_file_name);
      return EOF;
    }

  if (c == '\n')
    {
      line_number++;
      char_in_line = 0;
    }
  else
    char_in_line++;

  return c;
}

static void
phase1_ungetc (c)
     int c;
{
  if (c != EOF)
    {
      if (c == '\n')
	{
	  --line_number;
	  char_in_line = INT_MAX;
	}
      else
	--char_in_line;

      ungetc (c, fp);
    }
}


/* 2. Replace each comment that is not inside a character constant or
   string literal with a space character.  We need to remember the
   comment for later, because it may be attached to a keyword string.
   YCP comments can be in C comment syntax, C++ comment syntax or sh
   comment syntax.  */

static unsigned char phase2_pushback[1];
static int phase2_pushback_length;

static int
phase2_getc ()
{
  static char *buffer;
  static size_t bufmax;
  size_t buflen;
  int lineno;
  int c;
  bool last_was_star;

  if (phase2_pushback_length)
    return phase2_pushback[--phase2_pushback_length];

  if (char_in_line == 0)
    {
      /* Eat whitespace, to recognize ^[\t ]*# pattern.  */
      do
	c = phase1_getc ();
      while (c == '\t' || c == ' ');

      if (c == '#')
	{
	  /* sh comment.  */
	  buflen = 0;
	  lineno = line_number;
	  for (;;)
	    {
	      c = phase1_getc ();
	      if (c == '\n' || c == EOF)
		break;
	      if (buflen >= bufmax)
		{
		  bufmax += 100;
		  buffer = xrealloc (buffer, bufmax);
		}
	      buffer[buflen++] = c;
	    }
	  if (buflen >= bufmax)
	    {
	      bufmax += 100;
	      buffer = xrealloc (buffer, bufmax);
	    }
	  buffer[buflen] = '\0';
	  xgettext_comment_add (buffer);
	  last_comment_line = lineno;
	  return '\n';
	}
    }
  else
    c = phase1_getc ();

  if (c == '/')
    {
      c = phase1_getc ();

      switch (c)
	{
	default:
	  phase1_ungetc (c);
	  return '/';

	case '*':
	  /* C comment.  */
	  buflen = 0;
	  lineno = line_number;
	  last_was_star = false;
	  for (;;)
	    {
	      c = phase1_getc ();
	      if (c == EOF)
		break;
	      /* We skip all leading white space, but not EOLs.  */
	      if (buflen == 0 && isspace (c) && c != '\n')
		continue;
	      if (buflen >= bufmax)
		{
		  bufmax += 100;
		  buffer = xrealloc (buffer, bufmax);
	        }
	      buffer[buflen++] = c;
	      switch (c)
		{
		case '\n':
		  --buflen;
		  while (buflen >= 1
			 && (buffer[buflen - 1] == ' '
			     || buffer[buflen - 1] == '\t'))
		    --buflen;
		  buffer[buflen] = '\0';
		  xgettext_comment_add (buffer);
		  buflen = 0;
		  lineno = line_number;
		  last_was_star = false;
		  continue;

		case '*':
		  last_was_star = true;
		  continue;

		case '/':
		  if (last_was_star)
		    {
		      buflen -= 2;
		      while (buflen >= 1
			     && (buffer[buflen - 1] == ' '
				 || buffer[buflen - 1] == '\t'))
			--buflen;
		      buffer[buflen] = '\0';
		      xgettext_comment_add (buffer);
		      break;
		    }
		  /* FALLTHROUGH */

		default:
		  last_was_star = false;
		  continue;
		}
	      break;
	    }
	  last_comment_line = lineno;
	  return ' ';

	case '/':
	  /* C++ comment.  */
	  buflen = 0;
	  lineno = line_number;
	  for (;;)
	    {
	      c = phase1_getc ();
	      if (c == '\n' || c == EOF)
		break;
	      if (buflen >= bufmax)
		{
		  bufmax += 100;
		  buffer = xrealloc (buffer, bufmax);
		}
	      buffer[buflen++] = c;
	    }
	  if (buflen >= bufmax)
	    {
	      bufmax += 100;
	      buffer = xrealloc (buffer, bufmax);
	    }
	  buffer[buflen] = '\0';
	  xgettext_comment_add (buffer);
	  last_comment_line = lineno;
	  return '\n';
	}
    }
  else
    return c;
}

static void
phase2_ungetc (c)
     int c;
{
  if (c != EOF)
    phase2_pushback[phase2_pushback_length++] = c;
}


/* 7. Replace escape sequences within character strings with their
   single character equivalents.  */

#define P7_QUOTES (1000 + '"')

static int
phase7_getc ()
{
  int c;

  for (;;)
    {
      /* Use phase 1, because phase 2 elides comments.  */
      c = phase1_getc ();

      if (c == '"')
	return P7_QUOTES;
      if (c != '\\')
	return c;
      c = phase1_getc ();
      if (c != '\n')
	switch (c)
	  {
	  case 'b':
	    return '\b';
	  case 'f':
	    return '\f';
	  case 'n':
	    return '\n';
	  case 'r':
	    return '\r';
	  case 't':
	    return '\t';

	  /* FIXME: What is the octal escape syntax?
	     syntax.html says: [0] [0-7]+
	     scanner.ll says:  [0-7] [0-7] [0-7]
	   */
#if 0
	  case '0': case '1': case '2': case '3':
	  case '4': case '5': case '6': case '7':
	    {
	      int n, j;

	      n = 0;
	      for (j = 0; j < 3; ++j)
		{
		  n = n * 8 + c - '0';
		  c = phase1_getc ();
		  switch (c)
		    {
		    default:
		      break;

		    case '0': case '1': case '2': case '3':
		    case '4': case '5': case '6': case '7':
		      continue;
		    }
		  break;
		}
	      phase1_ungetc (c);
	      return n;
	    }
#endif

	  default:
	    return c;
	  }
    }
}


/* Combine characters into tokens.  Discard whitespace.  */

static void
x_ycp_lex (tp)
     token_ty *tp;
{
  static char *buffer;
  static int bufmax;
  int bufpos;
  int c;

  for (;;)
    {
      tp->line_number = line_number;
      c = phase2_getc ();

      switch (c)
	{
	case EOF:
	  tp->type = token_type_eof;
	  return;

	case '\n':
	  if (last_non_comment_line > last_comment_line)
	    xgettext_comment_reset ();
	  /* FALLTHROUGH */
	case '\r':
	case '\t':
	case ' ':
	  /* Ignore whitespace and comments.  */
	  continue;
	}

      last_non_comment_line = tp->line_number;

      switch (c)
	{
	case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
	case 'G': case 'H': case 'I': case 'J': case 'K': case 'L':
	case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R':
	case 'S': case 'T': case 'U': case 'V': case 'W': case 'X':
	case 'Y': case 'Z':
	case '_':
	case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
	case 'g': case 'h': case 'i': case 'j': case 'k': case 'l':
	case 'm': case 'n': case 'o': case 'p': case 'q': case 'r':
	case 's': case 't': case 'u': case 'v': case 'w': case 'x':
	case 'y': case 'z':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	  /* Symbol, or part of a number.  */
	  bufpos = 0;
	  for (;;)
	    {
	      if (bufpos >= bufmax)
		{
		  bufmax += 100;
		  buffer = xrealloc (buffer, bufmax);
		}
	      buffer[bufpos++] = c;
	      c = phase2_getc ();
	      switch (c)
		{
		case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
		case 'G': case 'H': case 'I': case 'J': case 'K': case 'L':
		case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R':
		case 'S': case 'T': case 'U': case 'V': case 'W': case 'X':
		case 'Y': case 'Z':
		case '_':
		case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
		case 'g': case 'h': case 'i': case 'j': case 'k': case 'l':
		case 'm': case 'n': case 'o': case 'p': case 'q': case 'r':
		case 's': case 't': case 'u': case 'v': case 'w': case 'x':
		case 'y': case 'z':
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		  continue;
		default:
		  if (bufpos == 1 && buffer[0] == '_' && c == '(')
		    {
		      tp->type = token_type_i18n;
		      return;
		    }
		  phase2_ungetc (c);
		  break;
		}
	      break;
	    }
	  if (bufpos >= bufmax)
	    {
	      bufmax += 100;
	      buffer = xrealloc (buffer, bufmax);
	    }
	  buffer[bufpos] = '\0';
	  tp->string = xstrdup (buffer);
	  tp->type = token_type_symbol;
	  return;

	case '"':
	  bufpos = 0;
	  for (;;)
	    {
	      c = phase7_getc ();
	      if (c == EOF || c == P7_QUOTES)
		break;
	      if (bufpos >= bufmax)
		{
		  bufmax += 100;
		  buffer = xrealloc (buffer, bufmax);
		}
	      buffer[bufpos++] = c;
	    }
	  if (bufpos >= bufmax)
	    {
	      bufmax += 100;
	      buffer = xrealloc (buffer, bufmax);
	    }
	  buffer[bufpos] = '\0';
	  tp->string = xstrdup (buffer);
	  tp->type = token_type_string_literal;
	  return;

	case '(':
	  tp->type = token_type_lparen;
	  return;

	case ')':
	  tp->type = token_type_rparen;
	  return;

	case ',':
	  tp->type = token_type_comma;
	  return;

	default:
	  /* We could carefully recognize each of the 2 and 3 character
	     operators, but it is not necessary, as we only need to recognize
	     gettext invocations.  Don't bother.  */
	  tp->type = token_type_other;
	  return;
	}
    }
}


void
extract_ycp (f, real_filename, logical_filename, mdlp)
     FILE *f;
     const char *real_filename;
     const char *logical_filename;
     msgdomain_list_ty *mdlp;
{
  message_list_ty *mlp = mdlp->item[0]->messages;
  int state;
  message_ty *plural_mp = NULL;	/* defined only when in states 1 and 2 */

  /* The file is broken into tokens.
     Normal handling: Look for
       [A] _( [B] msgid ... )
     Plural handling: Look for
       [A] _( [B] msgid [C] , [D] msgid_plural ... )
     At point [A]: state == 0.
     At point [B]: state == 1, plural_mp == NULL.
     At point [C]: state == 2, plural_mp != NULL.
     At point [D]: state == 1, plural_mp != NULL.  */

  fp = f;
  real_file_name = real_filename;
  logical_file_name = xstrdup (logical_filename);
  line_number = 1;
  char_in_line = 0;

  last_comment_line = -1;
  last_non_comment_line = -1;

  /* Start state is 0.  */
  state = 0;

  for (;;)
    {
      token_ty token;

      x_ycp_lex (&token);
      switch (token.type)
	{
	case token_type_i18n:
	  state = 1;
	  plural_mp = NULL;
	  continue;

	case token_type_string_literal:
	  if (state == 1)
	    {
	      lex_pos_ty pos;
	      pos.file_name = logical_file_name;
	      pos.line_number = token.line_number;

	      if (plural_mp == NULL)
		{
		  /* Seen an msgid.  */
		  plural_mp = remember_a_message (mlp, token.string, &pos);
		  state = 2;
		}
	      else
		{
		  /* Seen an msgid_plural.  */
		  remember_a_message_plural (plural_mp, token.string, &pos);
		  state = 0;
		}
	    }
	  else
	    {
	      free (token.string);
	      state = 0;
	    }
	  continue;

	case token_type_comma:
	  if (state == 2)
	    state = 1;
	  else
	    state = 0;
	  continue;

	case token_type_eof:
	  break;

	case token_type_symbol:
	  free (token.string);
	  /* FALLTHROUGH */
	default:
	  state = 0;
	  continue;
	}
      break;
    }

  fp = NULL;
  real_file_name = NULL;
  logical_file_name = NULL;
  line_number = 0;
  char_in_line = 0;
}
