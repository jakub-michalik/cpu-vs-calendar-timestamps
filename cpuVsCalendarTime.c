#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

int main(void) {
  clock_t start_cpu, end_cpu;
  double cpu_time_used;
  double i, j;
  
  start_cpu = clock();
  
  /* increase the computational intensity with complex operations */
  for (i = 0; i < 100000000; i++) {
    j = sqrt(i) * pow(i, 2);
  }
  
  usleep(200000); // 200ms

  end_cpu = clock();
  cpu_time_used = ((double)(end_cpu - start_cpu)) / CLOCKS_PER_SEC;
  printf("CPU time elapsed %lf \n", cpu_time_used);

  long start, end;
  struct timeval timecheck;

  gettimeofday( & timecheck, NULL);
  start = (long) timecheck.tv_sec * 1000 + (long) timecheck.tv_usec / 1000;

  for (i = 0; i < 100000000; i++) {
    j = sqrt(i) * pow(i, 2);
  }
  
  usleep(200000); // 200ms

  gettimeofday( & timecheck, NULL);
  end = (long) timecheck.tv_sec * 1000 + (long) timecheck.tv_usec / 1000;

  printf("Milliseconds elapsed %ld \n", (end - start));

  return 0;
}
