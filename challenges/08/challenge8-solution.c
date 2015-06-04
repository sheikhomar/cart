#include <stdio.h>
#include <stdlib.h>


void average_array(long *arr, int size, long* res) {
    int i;

    for (i = size-1; i >= 0; i--) {
        *res = *res + arr[i];
    }
    *res = *res / size;
}


void average_array_v2(long *arr, int size, long* res) {
    int i;
    long temp = 0;
    for (i = size-1; i >= 0; i--) {
        temp = temp + arr[i];
    }
    *res = temp / size;
}


void average_array_v3(long *arr, int size, long* res) {
    int i;
    long temp0 = 0;
    long temp1 = 0;
    long temp2 = 0;
    // i = size-1; i >= 0; i--
    for (i = 0; i < size; i+=3) {
        temp0 = temp0 + arr[i];
        temp1 = temp1 + arr[i+1];
        temp2 = temp2 + arr[i+2];
    }

    for (; i < size; i++) {
      temp0 = temp0 + arr[i];
    }
    
    *res = (temp0+temp1+temp2) / size;
}


void average_array_v4(long *arr, int size, long* res) {
    int i;
    long temp0 = 0;
    long temp1 = 0;
    long temp2 = 0;
    long temp3 = 0;
    long temp4 = 0;
    long temp5 = 0;
    // i = size-1; i >= 0; i--
    for (i = 0; i < size; i+=6) {
        temp0 += arr[i];
        temp1 += arr[i+1];
        temp2 += arr[i+2];
        temp3 += arr[i+3];
        temp4 += arr[i+4];
        temp5 += arr[i+5];
    }

    for (; i < size; i++) {
      temp0 = temp0 + arr[i];
    }
    
    *res = (temp0+temp1+temp2) / size;
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
    average_array_v3(the_array, SIZE, &avg);
    average_array_v3(the_array, SIZE, &avg);
    average_array_v3(the_array, SIZE, &avg);
    average_array_v3(the_array, SIZE, &avg);
    average_array_v3(the_array, SIZE, &avg);
    printf("Average: %ld\n", avg);
    return 0;
}
