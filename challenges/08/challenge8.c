#include <stdio.h>
#include <stdlib.h>


void average_array(long *arr, int size, long* res) {
    int i;

    for (i = size-1; i >= 0; i--) {
        *res = *res + arr[i];
    }
    *res = *res / size;
}

#define SIZE 1024*1024*32
long the_array[SIZE];

void init_array(long *arr, int size) {
    int i;
    for (i = 0; i < size; i++)
        arr[i] = rand() % 1024;
}


int main() {
    init_array(the_array, SIZE);
    long avg = 0;
    average_array(the_array, SIZE, &avg);
    printf("Average: %ld\n", avg);
    return 0;
}
