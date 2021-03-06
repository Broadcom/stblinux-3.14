# This script will disable the system-wide tap on the given list of events
# passed as parameter, and stop the tap at each other "normal rate" events.

#excluding core markers (already connected)
#excluding locking markers (high traffic)

echo Disconnecting function markers

# interesting period starts with the list of events passed as parameter.
START_FTRACE=$*

# interesting period may stop with one specific event, but also try to keep the
# other START_FTRACE events triggers to the lowest possible overhead by stopping
# function trace at every other events.
# Do _not_ disable function tracing in ftrace_entry event unless you really only
# want the first function entry...
STOP_FTRACE=`cat /proc/ltt|grep -v %k|awk '{print $2}'|sort -u|grep -v ^core_|grep -v ^locking_|grep -v ^lockdep|grep -v ftrace_entry|grep -v ^tap_`

for a in $START_FTRACE; do
	STOP_FTRACE=`echo $STOP_FTRACE|sed 's/$a//'`
done

for a in $START_FTRACE; do
	echo Disconnecting start $a
	echo "disconnect $a ftrace_system_start" > /proc/ltt
done

for a in $STOP_FTRACE; do
	echo Disconnecting stop $a
	echo "disconnect $a ftrace_system_stop" > /proc/ltt
done


