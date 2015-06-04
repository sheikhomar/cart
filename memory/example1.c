#include <stdio.h>
#define ARRAY_SIZE 64*1024*1024

int main(void) {
  int arr[ARRAY_SIZE];
  int i;

  for (i = 0; i < ARRAY_SIZE; i++)
    arr[i] *= 3;
  for (i = 0; i < ARRAY_SIZE; i++)
    arr[i] *= 3;
  
  printf("Hello world!\n");
  return 0;
}
