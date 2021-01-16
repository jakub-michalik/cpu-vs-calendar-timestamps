#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  clock_t start_cpu, end_cpu;
  double cpu_time_used;
  double i;
  start_cpu = clock();
  for (i = 0; i < 100000000; i++) {
    i += 3;
  }
  usleep(200000); // 200ms

  end_cpu = clock();
  cpu_time_used = ((double)(end_cpu - start_cpu)) / CLOCKS_PER_SEC;
  printf("CPU time elapsed %lf \n", cpu_time_used);

  long start, end;
  struct timeval timecheck;

  gettimeofday( & timecheck, NULL);
  start = (long) timecheck.tv_sec * 1000 + (long) timecheck.tv_usec / 1000;

  usleep(200000); // 200ms
  for (i = 0; i < 100000000; i++) {
    i += 3;
  }

  gettimeofday( & timecheck, NULL);
  end = (long) timecheck.tv_sec * 1000 + (long) timecheck.tv_usec / 1000;

  printf("Milliseconds elapsed %ld \n", (end - start));

}
