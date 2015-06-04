
int add(int a, int b) {
    /* return a + b; */
    int output;
    asm (
         "movl %1, %%eax;"
         "movl %2, %%ebx;"
         "addl %%ebx, %%eax;"
         "movl $42, %0;"
         : "=r"(output) /*output*/
         : "r"(a), "r"(b)/*input*/
         : "eax", "ebx", "ecx" /*clobbers*/
    );
    return output;
}

int sub(int a, int b) {
    //return a - b;
}

int mul(int a, int b) {
    //return a*b;
}

int array_access(int a[], int b) {
    //return a[b];

}

int safe_add(int a, int b, int *overflow) {
    /* must set *overflow = 1 if overflow occured, and 0 otherwise! */
    /* HINT! Der findes assembler instruktionen "seto" */
    /* return a + b; */
}
