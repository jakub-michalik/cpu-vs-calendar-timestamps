# CPU vs calendar timestamps

The concept of time in computing can be a bit confusing due to the existence of different types of time measurements, namely the calendar time and the CPU time.

Calendar time, also known as wall-clock time, is what we typically think of when we talk about time - the seconds, minutes, and hours that pass on the clock on the wall. This is the total time that elapses from the start to the end of a program's execution, regardless of what else is happening on the system.

On the other hand, CPU time is the actual time the CPU spends executing a specific program or process, excluding any time during which the process is waiting for I/O operations or other system tasks to complete. This is a crucial performance metric as it gives a more precise measure of the processor resources a process or program is consuming.

In POSIX systems, these two types of time can be quite different due to multitasking, where processes can be in a waiting state while other processes are scheduled to run by the operating system. It's important to note that POSIX is a family of standards specified by the IEEE for maintaining compatibility between operating systems.

This difference can be demonstrated by a function like usleep(), which suspends the execution of the current thread for a specified number of microseconds. While the CPU time for the process is paused during this period, the calendar time will continue to tick forward. 

The discrepancy between CPU time and calendar time can manifest in different scenarios. In an ideal scenario, if a process is the only one running without interruptions or system-level delays, both CPU time and calendar time would be almost equal. However, if several processes compete for CPU resources or if a process spends a substantial amount of time waiting for I/O operations, the CPU time will be significantly less than the calendar time. 

Understanding the distinction between CPU time and calendar time is crucial for optimizing and debugging software. For programmers seeking to measure the efficiency and performance of their code, CPU time provides a more accurate measure of a program's resource usage and execution speed, essential factors in code optimization and resource management. 

In conclusion, while calendar time is a macro-level, exterior measure of time passage, CPU time serves as a micro-level, interior measure of a program's execution and resource usage. Both are important, but serve different purposes in system level programming and software optimization strategies.

## Code example ![example workflow](https://github.com/jakub-michalik/cpu-vs-calendar-timestamps/actions/workflows/cmake-multi-platform.yml/badge.svg)


