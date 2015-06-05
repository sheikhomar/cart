#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int pipelined_slowest_latency(int registerDelay, int logicDelays[], int count) {
  int i, slowest = 0;
  for (i = 0; i < count; i++) {
    if (logicDelays[i] > slowest)
      slowest = logicDelays[i];
  }
  return slowest + registerDelay;
}
int pipelined_latency(int registerDelay, int logicDelays[], int count) {
  int slowest = pipelined_slowest_latency(registerDelay, logicDelays, count);
  return slowest * count;
}

double pipelined_throughput(int registerDelay, int logicDelays[], int count) {
  int slowest = pipelined_slowest_latency(registerDelay, logicDelays, count);
  return (1 / (double)slowest) * 1000;
}

int logic_latency(int registerDelay, int logicDelays[], int count) {
  int i, sum = 0;
  for (i = 0; i < count; i++) {
    sum += logicDelays[i];
  }
  return sum + registerDelay;
}

double logic_throughput(int registerDelay, int logicDelays[], int count) {
  int latency = logic_latency(registerDelay, logicDelays, count);
  return (1 / (double)latency) * 1000;
}

void test1() {
  int registerDelay = 20;
  int logic[3] = { 50, 150, 100};
  int count = 3;
  
  int slowest = pipelined_slowest_latency(registerDelay, logic, count);
  printf("Slowest Logic: %d ps \n", slowest);
  int latency = pipelined_latency(registerDelay, logic, count);
  printf("Latency:       %d ps \n", latency);
  double throughput = pipelined_throughput(registerDelay, logic, count);
  printf("Througput:     %f GIPS \n\n", throughput);
}

void test2() {
  int registerDelay = 20;
  int logic[6] = { 50, 50, 50, 50, 50, 50};
  int count = 6;
  
  int slowest = pipelined_slowest_latency(registerDelay, logic, count);
  printf("Slowest Logic: %d ps \n", slowest);
  int latency = pipelined_latency(registerDelay, logic, count);
  printf("Latency:       %d ps \n", latency);
  double throughput = pipelined_throughput(registerDelay, logic, count);
  printf("Througput:     %f GIPS \n\n", throughput);
}

void test3() {
  int registerDelay = 20;
  int logic[6] = { 80, 30, 60, 50, 70, 10};
  int count = 6;
  
  int latency = logic_latency(registerDelay, logic, count);
  printf("Latency:       %d ps \n", latency);
  double throughput = logic_throughput(registerDelay, logic, count);
  printf("Througput:     %f GIPS \n", throughput);
}

int main() {
  test1();
  test2();
  test3();

  return 0; 
}
