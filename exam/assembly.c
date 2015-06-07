#include <stdio.h>

int add(int a, int b) {
    int output;
    asm (
         "movl %1, %%eax;"
         "movl %2, %%ebx;"
         "addl %%ebx, %%eax;"
         "movl %%eax, %0;"
         : "=r"(output) /*output*/
         : "r"(a), "r"(b)/*input*/
         : "eax", "ebx", "ecx" /*clobbers*/
    );
    return output;
}

int sub(int a, int b) {
    int output;
    asm (
         "movl %1, %%eax;"
         "movl %2, %%ebx;"
         "subl %%ebx, %%eax;"
         "movl %%eax, %0;"
         : "=r"(output) /*output*/
         : "r"(a), "r"(b)/*input*/
         : "eax", "ebx", "ecx" /*clobbers*/
    );
    return output;
}

int mul(int a, int b) {
    int output;
    asm (
         "movl %1, %%eax;"
         "movl %2, %%ebx;"
         "imull %%ebx, %%eax;"
         "movl %%eax, %0;"
         : "=r"(output) /*output*/
         : "r"(a), "r"(b)/*input*/
         : "eax", "ebx", "ecx" /*clobbers*/
    );
    return output;
}

int array_access(int a[], int b) {
    int output;
    asm (
         "movl %1, %%eax;" // eax = a
         "movl %2, %%ebx;" // ebx = b
         "movl (%%eax,%%ebx,4), %0;"
         : "=r"(output) /*output*/
         : "r"(a), "r"(b)/*input*/
         : "eax", "ebx", "ecx" /*clobbers*/
    );
    return output;
}

int safe_add(int a, int b, int *overflow) {
    /* must set *overflow = 1 if overflow occured, and 0 otherwise! */
    /* HINT! Der findes assembler instruktionen "seto" */
    return a + b;
}

int main() {
  int array[3] = { 1, 2, 3};
  printf("Add %d\n", add(1, 3));
  printf("Subtract %d\n", sub(7, 3));
  printf("Multiplication %d\n", mul(7, 3));
  printf("Array[1] = %d\n", array_access(array, 1));
  printf("Array[0] = %d\n", array_access(array, 0));
  printf("Array[2] = %d\n", array_access(array, 2));
  return 0;
}
