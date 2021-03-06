/****************************************************************************
 *     Copyright (c) 1999-2014, Broadcom Corporation
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 ***************************************************************************/

#ifndef BCHP_XPT_PMU_H__
#define BCHP_XPT_PMU_H__

/***************************************************************************
 *XPT_PMU - XPT PMU Control Registers
 ***************************************************************************/
#define BCHP_XPT_PMU_CLK_CTRL                    0x00a00200 /* [RW] Power Management control */
#define BCHP_XPT_PMU_RBUS_RSP_CTRL               0x00a00204 /* [RW] Power Management control */
#define BCHP_XPT_PMU_RBUS_RSP_VAL                0x00a00208 /* [RW] Power Management control */
#define BCHP_XPT_PMU_PSM_VDD_CTRL                0x00a0020c /* [RW] Power Management control */
#define BCHP_XPT_PMU_STBY_CTRL                   0x00a00210 /* [RW] Power Management control */
#define BCHP_XPT_PMU_MEM_INIT_CTRL               0x00a00214 /* [RW] Power Management control */
#define BCHP_XPT_PMU_MEMDMA_SW_INIT_CTRL         0x00a00218 /* [RW] Power Management control */

/***************************************************************************
 *CLK_CTRL - Power Management control
 ***************************************************************************/
/* XPT_PMU :: CLK_CTRL :: reserved0 [31:20] */
#define BCHP_XPT_PMU_CLK_CTRL_reserved0_MASK                       0xfff00000
#define BCHP_XPT_PMU_CLK_CTRL_reserved0_SHIFT                      20

/* XPT_PMU :: CLK_CTRL :: TSIO_DISABLE [19:19] */
#define BCHP_XPT_PMU_CLK_CTRL_TSIO_DISABLE_MASK                    0x00080000
#define BCHP_XPT_PMU_CLK_CTRL_TSIO_DISABLE_SHIFT                   19
#define BCHP_XPT_PMU_CLK_CTRL_TSIO_DISABLE_DEFAULT                 0x00000000

/* XPT_PMU :: CLK_CTRL :: MEMDMA_DISABLE [18:18] */
#define BCHP_XPT_PMU_CLK_CTRL_MEMDMA_DISABLE_MASK                  0x00040000
#define BCHP_XPT_PMU_CLK_CTRL_MEMDMA_DISABLE_SHIFT                 18
#define BCHP_XPT_PMU_CLK_CTRL_MEMDMA_DISABLE_DEFAULT               0x00000000

/* XPT_PMU :: CLK_CTRL :: FULL_PID_PARSER_DISABLE [17:17] */
#define BCHP_XPT_PMU_CLK_CTRL_FULL_PID_PARSER_DISABLE_MASK         0x00020000
#define BCHP_XPT_PMU_CLK_CTRL_FULL_PID_PARSER_DISABLE_SHIFT        17
#define BCHP_XPT_PMU_CLK_CTRL_FULL_PID_PARSER_DISABLE_DEFAULT      0x00000000

/* XPT_PMU :: CLK_CTRL :: WAKEUP_DISABLE [16:16] */
#define BCHP_XPT_PMU_CLK_CTRL_WAKEUP_DISABLE_MASK                  0x00010000
#define BCHP_XPT_PMU_CLK_CTRL_WAKEUP_DISABLE_SHIFT                 16
#define BCHP_XPT_PMU_CLK_CTRL_WAKEUP_DISABLE_DEFAULT               0x00000000

/* XPT_PMU :: CLK_CTRL :: RMX1_DISABLE [15:15] */
#define BCHP_XPT_PMU_CLK_CTRL_RMX1_DISABLE_MASK                    0x00008000
#define BCHP_XPT_PMU_CLK_CTRL_RMX1_DISABLE_SHIFT                   15
#define BCHP_XPT_PMU_CLK_CTRL_RMX1_DISABLE_DEFAULT                 0x00000000

/* XPT_PMU :: CLK_CTRL :: RMX0_DISABLE [14:14] */
#define BCHP_XPT_PMU_CLK_CTRL_RMX0_DISABLE_MASK                    0x00004000
#define BCHP_XPT_PMU_CLK_CTRL_RMX0_DISABLE_SHIFT                   14
#define BCHP_XPT_PMU_CLK_CTRL_RMX0_DISABLE_DEFAULT                 0x00000000

/* XPT_PMU :: CLK_CTRL :: MPOD_DISABLE [13:13] */
#define BCHP_XPT_PMU_CLK_CTRL_MPOD_DISABLE_MASK                    0x00002000
#define BCHP_XPT_PMU_CLK_CTRL_MPOD_DISABLE_SHIFT                   13
#define BCHP_XPT_PMU_CLK_CTRL_MPOD_DISABLE_DEFAULT                 0x00000000

/* XPT_PMU :: CLK_CTRL :: XPT_IO_DISABLE [12:12] */
#define BCHP_XPT_PMU_CLK_CTRL_XPT_IO_DISABLE_MASK                  0x00001000
#define BCHP_XPT_PMU_CLK_CTRL_XPT_IO_DISABLE_SHIFT                 12
#define BCHP_XPT_PMU_CLK_CTRL_XPT_IO_DISABLE_DEFAULT               0x00000000

/* XPT_PMU :: CLK_CTRL :: PB_DISABLE [11:11] */
#define BCHP_XPT_PMU_CLK_CTRL_PB_DISABLE_MASK                      0x00000800
#define BCHP_XPT_PMU_CLK_CTRL_PB_DISABLE_SHIFT                     11
#define BCHP_XPT_PMU_CLK_CTRL_PB_DISABLE_DEFAULT                   0x00000000

/* XPT_PMU :: CLK_CTRL :: PSUB_DISABLE [10:10] */
#define BCHP_XPT_PMU_CLK_CTRL_PSUB_DISABLE_MASK                    0x00000400
#define BCHP_XPT_PMU_CLK_CTRL_PSUB_DISABLE_SHIFT                   10
#define BCHP_XPT_PMU_CLK_CTRL_PSUB_DISABLE_DEFAULT                 0x00000000

/* XPT_PMU :: CLK_CTRL :: BUS_IF_DISABLE [09:09] */
#define BCHP_XPT_PMU_CLK_CTRL_BUS_IF_DISABLE_MASK                  0x00000200
#define BCHP_XPT_PMU_CLK_CTRL_BUS_IF_DISABLE_SHIFT                 9
#define BCHP_XPT_PMU_CLK_CTRL_BUS_IF_DISABLE_DEFAULT               0x00000000

/* XPT_PMU :: CLK_CTRL :: PCROFFSET_DISABLE [08:08] */
#define BCHP_XPT_PMU_CLK_CTRL_PCROFFSET_DISABLE_MASK               0x00000100
#define BCHP_XPT_PMU_CLK_CTRL_PCROFFSET_DISABLE_SHIFT              8
#define BCHP_XPT_PMU_CLK_CTRL_PCROFFSET_DISABLE_DEFAULT            0x00000000

/* XPT_PMU :: CLK_CTRL :: RAVE_DISABLE [07:07] */
#define BCHP_XPT_PMU_CLK_CTRL_RAVE_DISABLE_MASK                    0x00000080
#define BCHP_XPT_PMU_CLK_CTRL_RAVE_DISABLE_SHIFT                   7
#define BCHP_XPT_PMU_CLK_CTRL_RAVE_DISABLE_DEFAULT                 0x00000000

/* XPT_PMU :: CLK_CTRL :: MSG_DISABLE [06:06] */
#define BCHP_XPT_PMU_CLK_CTRL_MSG_DISABLE_MASK                     0x00000040
#define BCHP_XPT_PMU_CLK_CTRL_MSG_DISABLE_SHIFT                    6
#define BCHP_XPT_PMU_CLK_CTRL_MSG_DISABLE_DEFAULT                  0x00000000

/* XPT_PMU :: CLK_CTRL :: DPCR_DISABLE [05:05] */
#define BCHP_XPT_PMU_CLK_CTRL_DPCR_DISABLE_MASK                    0x00000020
#define BCHP_XPT_PMU_CLK_CTRL_DPCR_DISABLE_SHIFT                   5
#define BCHP_XPT_PMU_CLK_CTRL_DPCR_DISABLE_DEFAULT                 0x00000000

/* XPT_PMU :: CLK_CTRL :: XMEMIF_216_DISABLE [04:04] */
#define BCHP_XPT_PMU_CLK_CTRL_XMEMIF_216_DISABLE_MASK              0x00000010
#define BCHP_XPT_PMU_CLK_CTRL_XMEMIF_216_DISABLE_SHIFT             4
#define BCHP_XPT_PMU_CLK_CTRL_XMEMIF_216_DISABLE_DEFAULT           0x00000000

/* XPT_PMU :: CLK_CTRL :: XMEMIF_108_DISABLE [03:03] */
#define BCHP_XPT_PMU_CLK_CTRL_XMEMIF_108_DISABLE_MASK              0x00000008
#define BCHP_XPT_PMU_CLK_CTRL_XMEMIF_108_DISABLE_SHIFT             3
#define BCHP_XPT_PMU_CLK_CTRL_XMEMIF_108_DISABLE_DEFAULT           0x00000000

/* XPT_PMU :: CLK_CTRL :: XCBUFF_DISABLE [02:02] */
#define BCHP_XPT_PMU_CLK_CTRL_XCBUFF_DISABLE_MASK                  0x00000004
#define BCHP_XPT_PMU_CLK_CTRL_XCBUFF_DISABLE_SHIFT                 2
#define BCHP_XPT_PMU_CLK_CTRL_XCBUFF_DISABLE_DEFAULT               0x00000000

/* XPT_PMU :: CLK_CTRL :: RSBUFF_DISABLE [01:01] */
#define BCHP_XPT_PMU_CLK_CTRL_RSBUFF_DISABLE_MASK                  0x00000002
#define BCHP_XPT_PMU_CLK_CTRL_RSBUFF_DISABLE_SHIFT                 1
#define BCHP_XPT_PMU_CLK_CTRL_RSBUFF_DISABLE_DEFAULT               0x00000000

/* XPT_PMU :: CLK_CTRL :: FE_DISABLE [00:00] */
#define BCHP_XPT_PMU_CLK_CTRL_FE_DISABLE_MASK                      0x00000001
#define BCHP_XPT_PMU_CLK_CTRL_FE_DISABLE_SHIFT                     0
#define BCHP_XPT_PMU_CLK_CTRL_FE_DISABLE_DEFAULT                   0x00000000

/***************************************************************************
 *RBUS_RSP_CTRL - Power Management control
 ***************************************************************************/
/* XPT_PMU :: RBUS_RSP_CTRL :: reserved0 [31:02] */
#define BCHP_XPT_PMU_RBUS_RSP_CTRL_reserved0_MASK                  0xfffffffc
#define BCHP_XPT_PMU_RBUS_RSP_CTRL_reserved0_SHIFT                 2

/* XPT_PMU :: RBUS_RSP_CTRL :: RBUS_WR_RSP [01:01] */
#define BCHP_XPT_PMU_RBUS_RSP_CTRL_RBUS_WR_RSP_MASK                0x00000002
#define BCHP_XPT_PMU_RBUS_RSP_CTRL_RBUS_WR_RSP_SHIFT               1
#define BCHP_XPT_PMU_RBUS_RSP_CTRL_RBUS_WR_RSP_DEFAULT             0x00000000

/* XPT_PMU :: RBUS_RSP_CTRL :: RBUS_RD_RSP [00:00] */
#define BCHP_XPT_PMU_RBUS_RSP_CTRL_RBUS_RD_RSP_MASK                0x00000001
#define BCHP_XPT_PMU_RBUS_RSP_CTRL_RBUS_RD_RSP_SHIFT               0
#define BCHP_XPT_PMU_RBUS_RSP_CTRL_RBUS_RD_RSP_DEFAULT             0x00000000

/***************************************************************************
 *RBUS_RSP_VAL - Power Management control
 ***************************************************************************/
/* XPT_PMU :: RBUS_RSP_VAL :: RD_RSP_VAL [31:00] */
#define BCHP_XPT_PMU_RBUS_RSP_VAL_RD_RSP_VAL_MASK                  0xffffffff
#define BCHP_XPT_PMU_RBUS_RSP_VAL_RD_RSP_VAL_SHIFT                 0
#define BCHP_XPT_PMU_RBUS_RSP_VAL_RD_RSP_VAL_DEFAULT               0xdeaddead

/***************************************************************************
 *PSM_VDD_CTRL - Power Management control
 ***************************************************************************/
/* XPT_PMU :: PSM_VDD_CTRL :: reserved0 [31:14] */
#define BCHP_XPT_PMU_PSM_VDD_CTRL_reserved0_MASK                   0xffffc000
#define BCHP_XPT_PMU_PSM_VDD_CTRL_reserved0_SHIFT                  14

/* XPT_PMU :: PSM_VDD_CTRL :: TSIO_DISABLE [13:13] */
#define BCHP_XPT_PMU_PSM_VDD_CTRL_TSIO_DISABLE_MASK                0x00002000
#define BCHP_XPT_PMU_PSM_VDD_CTRL_TSIO_DISABLE_SHIFT               13
#define BCHP_XPT_PMU_PSM_VDD_CTRL_TSIO_DISABLE_DEFAULT             0x00000000

/* XPT_PMU :: PSM_VDD_CTRL :: MEMDMA_DISABLE [12:12] */
#define BCHP_XPT_PMU_PSM_VDD_CTRL_MEMDMA_DISABLE_MASK              0x00001000
#define BCHP_XPT_PMU_PSM_VDD_CTRL_MEMDMA_DISABLE_SHIFT             12
#define BCHP_XPT_PMU_PSM_VDD_CTRL_MEMDMA_DISABLE_DEFAULT           0x00000000

/* XPT_PMU :: PSM_VDD_CTRL :: PB_DISABLE [11:11] */
#define BCHP_XPT_PMU_PSM_VDD_CTRL_PB_DISABLE_MASK                  0x00000800
#define BCHP_XPT_PMU_PSM_VDD_CTRL_PB_DISABLE_SHIFT                 11
#define BCHP_XPT_PMU_PSM_VDD_CTRL_PB_DISABLE_DEFAULT               0x00000000

/* XPT_PMU :: PSM_VDD_CTRL :: PSUB_DISABLE [10:10] */
#define BCHP_XPT_PMU_PSM_VDD_CTRL_PSUB_DISABLE_MASK                0x00000400
#define BCHP_XPT_PMU_PSM_VDD_CTRL_PSUB_DISABLE_SHIFT               10
#define BCHP_XPT_PMU_PSM_VDD_CTRL_PSUB_DISABLE_DEFAULT             0x00000000

/* XPT_PMU :: PSM_VDD_CTRL :: PCROFFSET_DISABLE [09:09] */
#define BCHP_XPT_PMU_PSM_VDD_CTRL_PCROFFSET_DISABLE_MASK           0x00000200
#define BCHP_XPT_PMU_PSM_VDD_CTRL_PCROFFSET_DISABLE_SHIFT          9
#define BCHP_XPT_PMU_PSM_VDD_CTRL_PCROFFSET_DISABLE_DEFAULT        0x00000000

/* XPT_PMU :: PSM_VDD_CTRL :: RAVE_DISABLE [08:08] */
#define BCHP_XPT_PMU_PSM_VDD_CTRL_RAVE_DISABLE_MASK                0x00000100
#define BCHP_XPT_PMU_PSM_VDD_CTRL_RAVE_DISABLE_SHIFT               8
#define BCHP_XPT_PMU_PSM_VDD_CTRL_RAVE_DISABLE_DEFAULT             0x00000000

/* XPT_PMU :: PSM_VDD_CTRL :: MSG_DISABLE [07:07] */
#define BCHP_XPT_PMU_PSM_VDD_CTRL_MSG_DISABLE_MASK                 0x00000080
#define BCHP_XPT_PMU_PSM_VDD_CTRL_MSG_DISABLE_SHIFT                7
#define BCHP_XPT_PMU_PSM_VDD_CTRL_MSG_DISABLE_DEFAULT              0x00000000

/* XPT_PMU :: PSM_VDD_CTRL :: XMEMIF_DISABLE [06:06] */
#define BCHP_XPT_PMU_PSM_VDD_CTRL_XMEMIF_DISABLE_MASK              0x00000040
#define BCHP_XPT_PMU_PSM_VDD_CTRL_XMEMIF_DISABLE_SHIFT             6
#define BCHP_XPT_PMU_PSM_VDD_CTRL_XMEMIF_DISABLE_DEFAULT           0x00000000

/* XPT_PMU :: PSM_VDD_CTRL :: FPP_DISABLE [05:05] */
#define BCHP_XPT_PMU_PSM_VDD_CTRL_FPP_DISABLE_MASK                 0x00000020
#define BCHP_XPT_PMU_PSM_VDD_CTRL_FPP_DISABLE_SHIFT                5
#define BCHP_XPT_PMU_PSM_VDD_CTRL_FPP_DISABLE_DEFAULT              0x00000000

/* XPT_PMU :: PSM_VDD_CTRL :: XCBUFF_DISABLE [04:04] */
#define BCHP_XPT_PMU_PSM_VDD_CTRL_XCBUFF_DISABLE_MASK              0x00000010
#define BCHP_XPT_PMU_PSM_VDD_CTRL_XCBUFF_DISABLE_SHIFT             4
#define BCHP_XPT_PMU_PSM_VDD_CTRL_XCBUFF_DISABLE_DEFAULT           0x00000000

/* XPT_PMU :: PSM_VDD_CTRL :: RSBUFF_DISABLE [03:03] */
#define BCHP_XPT_PMU_PSM_VDD_CTRL_RSBUFF_DISABLE_MASK              0x00000008
#define BCHP_XPT_PMU_PSM_VDD_CTRL_RSBUFF_DISABLE_SHIFT             3
#define BCHP_XPT_PMU_PSM_VDD_CTRL_RSBUFF_DISABLE_DEFAULT           0x00000000

/* XPT_PMU :: PSM_VDD_CTRL :: FE_DISABLE [02:02] */
#define BCHP_XPT_PMU_PSM_VDD_CTRL_FE_DISABLE_MASK                  0x00000004
#define BCHP_XPT_PMU_PSM_VDD_CTRL_FE_DISABLE_SHIFT                 2
#define BCHP_XPT_PMU_PSM_VDD_CTRL_FE_DISABLE_DEFAULT               0x00000000

/* XPT_PMU :: PSM_VDD_CTRL :: WAKEUP_CFG_DISABLE [01:01] */
#define BCHP_XPT_PMU_PSM_VDD_CTRL_WAKEUP_CFG_DISABLE_MASK          0x00000002
#define BCHP_XPT_PMU_PSM_VDD_CTRL_WAKEUP_CFG_DISABLE_SHIFT         1
#define BCHP_XPT_PMU_PSM_VDD_CTRL_WAKEUP_CFG_DISABLE_DEFAULT       0x00000001

/* XPT_PMU :: PSM_VDD_CTRL :: RAVE_IMEM_DISABLE [00:00] */
#define BCHP_XPT_PMU_PSM_VDD_CTRL_RAVE_IMEM_DISABLE_MASK           0x00000001
#define BCHP_XPT_PMU_PSM_VDD_CTRL_RAVE_IMEM_DISABLE_SHIFT          0
#define BCHP_XPT_PMU_PSM_VDD_CTRL_RAVE_IMEM_DISABLE_DEFAULT        0x00000001

/***************************************************************************
 *STBY_CTRL - Power Management control
 ***************************************************************************/
/* XPT_PMU :: STBY_CTRL :: reserved0 [31:14] */
#define BCHP_XPT_PMU_STBY_CTRL_reserved0_MASK                      0xffffc000
#define BCHP_XPT_PMU_STBY_CTRL_reserved0_SHIFT                     14

/* XPT_PMU :: STBY_CTRL :: TSIO_DISABLE [13:13] */
#define BCHP_XPT_PMU_STBY_CTRL_TSIO_DISABLE_MASK                   0x00002000
#define BCHP_XPT_PMU_STBY_CTRL_TSIO_DISABLE_SHIFT                  13
#define BCHP_XPT_PMU_STBY_CTRL_TSIO_DISABLE_DEFAULT                0x00000000

/* XPT_PMU :: STBY_CTRL :: MEMDMA_DISABLE [12:12] */
#define BCHP_XPT_PMU_STBY_CTRL_MEMDMA_DISABLE_MASK                 0x00001000
#define BCHP_XPT_PMU_STBY_CTRL_MEMDMA_DISABLE_SHIFT                12
#define BCHP_XPT_PMU_STBY_CTRL_MEMDMA_DISABLE_DEFAULT              0x00000000

/* XPT_PMU :: STBY_CTRL :: PB_DISABLE [11:11] */
#define BCHP_XPT_PMU_STBY_CTRL_PB_DISABLE_MASK                     0x00000800
#define BCHP_XPT_PMU_STBY_CTRL_PB_DISABLE_SHIFT                    11
#define BCHP_XPT_PMU_STBY_CTRL_PB_DISABLE_DEFAULT                  0x00000000

/* XPT_PMU :: STBY_CTRL :: PSUB_DISABLE [10:10] */
#define BCHP_XPT_PMU_STBY_CTRL_PSUB_DISABLE_MASK                   0x00000400
#define BCHP_XPT_PMU_STBY_CTRL_PSUB_DISABLE_SHIFT                  10
#define BCHP_XPT_PMU_STBY_CTRL_PSUB_DISABLE_DEFAULT                0x00000000

/* XPT_PMU :: STBY_CTRL :: PCROFFSET_DISABLE [09:09] */
#define BCHP_XPT_PMU_STBY_CTRL_PCROFFSET_DISABLE_MASK              0x00000200
#define BCHP_XPT_PMU_STBY_CTRL_PCROFFSET_DISABLE_SHIFT             9
#define BCHP_XPT_PMU_STBY_CTRL_PCROFFSET_DISABLE_DEFAULT           0x00000000

/* XPT_PMU :: STBY_CTRL :: RAVE_DISABLE [08:08] */
#define BCHP_XPT_PMU_STBY_CTRL_RAVE_DISABLE_MASK                   0x00000100
#define BCHP_XPT_PMU_STBY_CTRL_RAVE_DISABLE_SHIFT                  8
#define BCHP_XPT_PMU_STBY_CTRL_RAVE_DISABLE_DEFAULT                0x00000000

/* XPT_PMU :: STBY_CTRL :: MSG_DISABLE [07:07] */
#define BCHP_XPT_PMU_STBY_CTRL_MSG_DISABLE_MASK                    0x00000080
#define BCHP_XPT_PMU_STBY_CTRL_MSG_DISABLE_SHIFT                   7
#define BCHP_XPT_PMU_STBY_CTRL_MSG_DISABLE_DEFAULT                 0x00000000

/* XPT_PMU :: STBY_CTRL :: XMEMIF_DISABLE [06:06] */
#define BCHP_XPT_PMU_STBY_CTRL_XMEMIF_DISABLE_MASK                 0x00000040
#define BCHP_XPT_PMU_STBY_CTRL_XMEMIF_DISABLE_SHIFT                6
#define BCHP_XPT_PMU_STBY_CTRL_XMEMIF_DISABLE_DEFAULT              0x00000000

/* XPT_PMU :: STBY_CTRL :: FPP_DISABLE [05:05] */
#define BCHP_XPT_PMU_STBY_CTRL_FPP_DISABLE_MASK                    0x00000020
#define BCHP_XPT_PMU_STBY_CTRL_FPP_DISABLE_SHIFT                   5
#define BCHP_XPT_PMU_STBY_CTRL_FPP_DISABLE_DEFAULT                 0x00000000

/* XPT_PMU :: STBY_CTRL :: XCBUFF_DISABLE [04:04] */
#define BCHP_XPT_PMU_STBY_CTRL_XCBUFF_DISABLE_MASK                 0x00000010
#define BCHP_XPT_PMU_STBY_CTRL_XCBUFF_DISABLE_SHIFT                4
#define BCHP_XPT_PMU_STBY_CTRL_XCBUFF_DISABLE_DEFAULT              0x00000000

/* XPT_PMU :: STBY_CTRL :: RSBUFF_DISABLE [03:03] */
#define BCHP_XPT_PMU_STBY_CTRL_RSBUFF_DISABLE_MASK                 0x00000008
#define BCHP_XPT_PMU_STBY_CTRL_RSBUFF_DISABLE_SHIFT                3
#define BCHP_XPT_PMU_STBY_CTRL_RSBUFF_DISABLE_DEFAULT              0x00000000

/* XPT_PMU :: STBY_CTRL :: FE_DISABLE [02:02] */
#define BCHP_XPT_PMU_STBY_CTRL_FE_DISABLE_MASK                     0x00000004
#define BCHP_XPT_PMU_STBY_CTRL_FE_DISABLE_SHIFT                    2
#define BCHP_XPT_PMU_STBY_CTRL_FE_DISABLE_DEFAULT                  0x00000000

/* XPT_PMU :: STBY_CTRL :: WAKEUP_CFG_DISABLE [01:01] */
#define BCHP_XPT_PMU_STBY_CTRL_WAKEUP_CFG_DISABLE_MASK             0x00000002
#define BCHP_XPT_PMU_STBY_CTRL_WAKEUP_CFG_DISABLE_SHIFT            1
#define BCHP_XPT_PMU_STBY_CTRL_WAKEUP_CFG_DISABLE_DEFAULT          0x00000001

/* XPT_PMU :: STBY_CTRL :: RAVE_IMEM_DISABLE [00:00] */
#define BCHP_XPT_PMU_STBY_CTRL_RAVE_IMEM_DISABLE_MASK              0x00000001
#define BCHP_XPT_PMU_STBY_CTRL_RAVE_IMEM_DISABLE_SHIFT             0
#define BCHP_XPT_PMU_STBY_CTRL_RAVE_IMEM_DISABLE_DEFAULT           0x00000001

/***************************************************************************
 *MEM_INIT_CTRL - Power Management control
 ***************************************************************************/
/* XPT_PMU :: MEM_INIT_CTRL :: reserved0 [31:06] */
#define BCHP_XPT_PMU_MEM_INIT_CTRL_reserved0_MASK                  0xffffffc0
#define BCHP_XPT_PMU_MEM_INIT_CTRL_reserved0_SHIFT                 6

/* XPT_PMU :: MEM_INIT_CTRL :: FE_PID_SPID_MEM_INIT [05:05] */
#define BCHP_XPT_PMU_MEM_INIT_CTRL_FE_PID_SPID_MEM_INIT_MASK       0x00000020
#define BCHP_XPT_PMU_MEM_INIT_CTRL_FE_PID_SPID_MEM_INIT_SHIFT      5
#define BCHP_XPT_PMU_MEM_INIT_CTRL_FE_PID_SPID_MEM_INIT_DEFAULT    0x00000000

/* XPT_PMU :: MEM_INIT_CTRL :: FPP_SCM_INIT [04:04] */
#define BCHP_XPT_PMU_MEM_INIT_CTRL_FPP_SCM_INIT_MASK               0x00000010
#define BCHP_XPT_PMU_MEM_INIT_CTRL_FPP_SCM_INIT_SHIFT              4
#define BCHP_XPT_PMU_MEM_INIT_CTRL_FPP_SCM_INIT_DEFAULT            0x00000000

/* XPT_PMU :: MEM_INIT_CTRL :: PCROFFSET_PID_MEM_INIT [03:03] */
#define BCHP_XPT_PMU_MEM_INIT_CTRL_PCROFFSET_PID_MEM_INIT_MASK     0x00000008
#define BCHP_XPT_PMU_MEM_INIT_CTRL_PCROFFSET_PID_MEM_INIT_SHIFT    3
#define BCHP_XPT_PMU_MEM_INIT_CTRL_PCROFFSET_PID_MEM_INIT_DEFAULT  0x00000000

/* XPT_PMU :: MEM_INIT_CTRL :: PCROFFSET_CFG_MEM_INIT [02:02] */
#define BCHP_XPT_PMU_MEM_INIT_CTRL_PCROFFSET_CFG_MEM_INIT_MASK     0x00000004
#define BCHP_XPT_PMU_MEM_INIT_CTRL_PCROFFSET_CFG_MEM_INIT_SHIFT    2
#define BCHP_XPT_PMU_MEM_INIT_CTRL_PCROFFSET_CFG_MEM_INIT_DEFAULT  0x00000000

/* XPT_PMU :: MEM_INIT_CTRL :: MSG_PID2BUF_MEM_INIT [01:01] */
#define BCHP_XPT_PMU_MEM_INIT_CTRL_MSG_PID2BUF_MEM_INIT_MASK       0x00000002
#define BCHP_XPT_PMU_MEM_INIT_CTRL_MSG_PID2BUF_MEM_INIT_SHIFT      1
#define BCHP_XPT_PMU_MEM_INIT_CTRL_MSG_PID2BUF_MEM_INIT_DEFAULT    0x00000000

/* XPT_PMU :: MEM_INIT_CTRL :: WAKEUP_CFG_MEM_INIT [00:00] */
#define BCHP_XPT_PMU_MEM_INIT_CTRL_WAKEUP_CFG_MEM_INIT_MASK        0x00000001
#define BCHP_XPT_PMU_MEM_INIT_CTRL_WAKEUP_CFG_MEM_INIT_SHIFT       0
#define BCHP_XPT_PMU_MEM_INIT_CTRL_WAKEUP_CFG_MEM_INIT_DEFAULT     0x00000000

/***************************************************************************
 *MEMDMA_SW_INIT_CTRL - Power Management control
 ***************************************************************************/
/* XPT_PMU :: MEMDMA_SW_INIT_CTRL :: reserved0 [31:02] */
#define BCHP_XPT_PMU_MEMDMA_SW_INIT_CTRL_reserved0_MASK            0xfffffffc
#define BCHP_XPT_PMU_MEMDMA_SW_INIT_CTRL_reserved0_SHIFT           2

/* XPT_PMU :: MEMDMA_SW_INIT_CTRL :: PMU_MEMDMA_SW_INIT [01:01] */
#define BCHP_XPT_PMU_MEMDMA_SW_INIT_CTRL_PMU_MEMDMA_SW_INIT_MASK   0x00000002
#define BCHP_XPT_PMU_MEMDMA_SW_INIT_CTRL_PMU_MEMDMA_SW_INIT_SHIFT  1
#define BCHP_XPT_PMU_MEMDMA_SW_INIT_CTRL_PMU_MEMDMA_SW_INIT_DEFAULT 0x00000000

/* XPT_PMU :: MEMDMA_SW_INIT_CTRL :: PMU_MEMDMA_SW_INIT_SEL [00:00] */
#define BCHP_XPT_PMU_MEMDMA_SW_INIT_CTRL_PMU_MEMDMA_SW_INIT_SEL_MASK 0x00000001
#define BCHP_XPT_PMU_MEMDMA_SW_INIT_CTRL_PMU_MEMDMA_SW_INIT_SEL_SHIFT 0
#define BCHP_XPT_PMU_MEMDMA_SW_INIT_CTRL_PMU_MEMDMA_SW_INIT_SEL_DEFAULT 0x00000000

#endif /* #ifndef BCHP_XPT_PMU_H__ */

/* End of File */
