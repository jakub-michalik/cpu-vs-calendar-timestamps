# cpu-vs-calendar-timestamps
Differences in the calculation of the calendar time and CPU time

If you’re trying to optimize your program or measure its efficiency, it’s very useful to know how much processor time it uses. For that, calendar time and elapsed times are useless because a process may spend time waiting for I/O or for other processes to use the CPU. However, by compileing this example you could check on your device and see the difference. 

To visualise the difference the function usleep() has been used. The usleep() function suspends execution of the calling thread and stops the CPU counter for (at least) usec microseconds. This usleep() may be lengthened slightly by any system activity or by the time spent processing the call or by the granularity of system timers.
