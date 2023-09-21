![example workflow](https://github.com/jakub-michalik/cpu-vs-calendar-timestamps/actions/workflows/cmake-multi-platform.yml/badge.svg)

# CPU vs calendar timestamps

The concept of time in computing can be a bit confusing due to the existence of different types of time measurements, namely the calendar time and the CPU time.

Calendar time, also known as wall-clock time, is what we typically think of when we talk about time - the seconds, minutes, and hours that pass on the clock on the wall. This is the total time that elapses from the start to the end of a program's execution, regardless of what else is happening on the system.

On the other hand, CPU time is the actual time the CPU spends executing a specific program or process, excluding any time during which the process is waiting for I/O operations or other system tasks to complete. This is a crucial performance metric as it gives a more precise measure of the processor resources a process or program is consuming.

In POSIX systems, these two types of time can be quite different due to multitasking, where processes can be in a waiting state while other processes are scheduled to run by the operating system. It's important to note that POSIX is a family of standards specified by the IEEE for maintaining compatibility between operating systems.

This difference can be demonstrated by a function like usleep(), which suspends the execution of the current thread for a specified number of microseconds. While the CPU time for the process is paused during this period, the calendar time will continue to tick forward. 

The discrepancy between CPU time and calendar time can manifest in different scenarios. In an ideal scenario, if a process is the only one running without interruptions or system-level delays, both CPU time and calendar time would be almost equal. However, if several processes compete for CPU resources or if a process spends a substantial amount of time waiting for I/O operations, the CPU time will be significantly less than the calendar time. 

Understanding the distinction between CPU time and calendar time is crucial for optimizing and debugging software. For programmers seeking to measure the efficiency and performance of their code, CPU time provides a more accurate measure of a program's resource usage and execution speed, essential factors in code optimization and resource management. 

In conclusion, while calendar time is a macro-level, exterior measure of time passage, CPU time serves as a micro-level, interior measure of a program's execution and resource usage. Both are important, but serve different purposes in system level programming and software optimization strategies.

## Usage

```
cd cpu-vs-calendar-timestamps
ccmake . 
make 
```

## The result

* CPU time elapsed 1.843870 
* Milliseconds elapsed 2054 

The results show that the CPU clock time taken (clock function) and the wall clock time (gettimeofday function) are not the same. Hence, these two measures reflect different aspects of running time.

1. Clock Function: The clock function measures the time the CPU spends executing instructions of the calling process. The CPU time is reported in "ticks" or "jiffies", as opposed to real time. These ticks are a direct measure of the CPU's work. Non-CPUs tasks like waiting for disk activity, waiting for its turn to be dispatched, waiting for a lock, etc, are not factors. The CPU time is a useful measure for understanding the actual load placed on CPU by the given code. In this program, it's approximately 1.84 seconds.

2. gettimeofday Function: This function gives the total elapsed time (wall-clock time) for the code's execution. This includes time spent executing the CPU instructions as well as time waiting for IO operations, waiting for resources (like locks), waiting for system calls, etc. This is why it's longer than the CPU time. In this program, it's approximately 2.05 seconds.

For the usleep function, the CPU isn't doing much work - it's just waiting for the sleep duration to end. That's why the CPU time doesn't increment significantly during the sleep, but the actual time (gettimeofday) still proceeds as usual.

In general, wall-clock time is what you experience as the running time of your code. But CPU time is a more accurate measure of how much actual CPU computation is being used. This is necessarily lesser or equal to wall-clock time. 

Lastly, the difference between CPU time and wall-clock time can provide some indication of how much time is spent in the CPU versus waiting for other system resources (like I/O, network, database queries, etc.). 

In a multi-threaded, multi-core or distributed computing environment, where multiple processors or machines are involved, measuring CPU time can be more complex, as the computation may be spread across different processing units.
