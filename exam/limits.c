#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print_test_case_1(unsigned int x1) {
  printf("  x1 > 0 is %s", (x1 > 0) ? "true " : "false");
  printf("   when x1 = %d \n", x1);
}

void test_case_1() {
  printf("Running test case 1\n");
  print_test_case_1(0);
}

void print_test_case_2(int y1) {
  printf("  y1 > 0 is %s", (y1 > 0) ? "true " : "false");
  printf("   when y1 = %d \n", y1);
}

void test_case_2() {
  printf("Running test case 2\n");
  print_test_case_2(0);
}

void print_test_case_3(int y2) {
  int y1 = INT_MIN;
  printf("  y1 + y2 < 0 is %s", (y1 + y2 < 0) ? "true " : "false");
  printf("   when y1 = %d and y2 = %d \n", y1, y2);
}

void test_case_3() {
  printf("Running test case 3\n");
  print_test_case_3(0);
  print_test_case_3(INT_MAX);
}

void print_test_case_4(unsigned int x2) {
  unsigned int x1 = 0;
  printf("  x1 + x2 > 0 is %s", (x1 + x2 > 0) ? "true " : "false");
  printf("   when x1 = %d and x2 = %d \n", x1, x2);
}

void test_case_4() {
  printf("Running test case 4\n");
  print_test_case_4(0);
  print_test_case_4(UINT_MAX);
}

void print_test_case_5(int y1) {
  unsigned int x1 = y1;
  printf("  x1 >= 0 is %s", (x1 >= 0) ? "true " : "false");
  printf("   when y1 = %d and x1 = %d \n", y1, x1);
}

void test_case_5() {
  printf("Running test case 5\n");
  print_test_case_5(0);
  print_test_case_5(INT_MAX);
}

void print_test_case_6(int y1) {
  int y2 = -y1;
  printf("  y2 > 0 is %s", (y2 > 0) ? "true " : "false");
  printf("   when y1 = %d and y2 = %d \n", y1, y2);
}

void test_case_6() {
  printf("Running test case 6\n");
  print_test_case_6(-1);
  print_test_case_6(INT_MIN);
}

int main() {
  test_case_1();
  test_case_2();
  test_case_3();
  test_case_4();
  test_case_5();
  test_case_6();

  return 0; 
}
