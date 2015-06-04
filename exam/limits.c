#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print_test_case_3(int y1) {
  unsigned int x1 = INT_MAX;
  printf("  y1 > x1 is %s", (y1 > x1) ? "true " : "false");
  printf("   when y1 = %d and x1 = %d \n", y1, x1);
}

void test_case_3() {
  printf("Running test case 3\n");
  print_test_case_3(INT_MIN);
  print_test_case_3(-1);
}

void print_test_case_4(int y1) {
  // Hvis y1 < 0 og x1 = y1 udføres, sa vil x1 > 0
  unsigned int x1 = y1;
  printf("  x1 > 0 is %s", (x1 > 0) ? "true " : "false");
  printf("   when y1 = %d and x1 = %d \n", y1, x1);
}

void test_case_4() {
  printf("Running test case 4\n");
  // Hvis y1 < 0 og x1 = y1 udføres, sa vil x1 > 0
  print_test_case_4(INT_MIN);
  print_test_case_4(-1);
}

void print_test_case_5(int y1) {
  // Hvis y1 < 0 og y2 = -y1 udføres, sa vil y2 > 0
  int y2 = -y1;
  printf("  y2 > 0 is %s", (y2 > 0) ? "true " : "false");
  printf("   when y1 = %d and y2 = %d \n", y1, y2);
}

void test_case_5() {
  printf("Running test case 5\n");
  // Hvis y1 < 0 og y2 = -y1 udføres, sa vil y2 > 0
  print_test_case_5(INT_MIN);
  print_test_case_5(-1);
}

void print_test_case_6(int y1, int y2) {
  // Hvis y1 < 0 og y2 < 0, sa vil y1 + y2 < 0
  printf("  y1 + y2 < 0 is %s", (y1+y2 < 0) ? "true " : "false");
  printf("   when y1 = %d and y2 = %d \n", y1, y2);
}

void test_case_6() {
  printf("Running test case 6\n");
  // Hvis y1 < 0 og y2 < 0, sa vil y1 + y2 < 0
  print_test_case_6(INT_MIN, INT_MIN);
  print_test_case_6(INT_MIN, -1);
  print_test_case_6(-1, INT_MIN);
  print_test_case_6(-1, -1);
}

int main() {
  test_case_3();
  test_case_4();
  test_case_5();
  test_case_6();

  return 0; 
}
