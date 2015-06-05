#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *to_binary(int x, int bit_count) {
  const int array_size = bit_count + (bit_count/4) + 2;
  char *b = calloc(array_size, sizeof(char));
  int z = 1 << (bit_count-1);
  int i = bit_count;
  for (; z > 0; z >>= 1, i--) {
    strcat(b, ((x & z) == z) ? "1" : "0");
    if (i % 4 == 1)
      strcat(b, " ");
  }

  return b;
}


void print_conversions(int number, int bits) {
  unsigned int unsigned_number = number;
  const int max_unsigned = (1 << (bits - 1));
  unsigned int bit_mask = (1 << bits) - 1;

  printf(" [%4d] ", number);
  printf(" %12s ", to_binary(number, bits));
  printf(" 0x%02X ", (number & bit_mask));
  printf(" %4d ", (unsigned_number & bit_mask));
  if (unsigned_number >= max_unsigned) {
    printf(" %4d ", ((number & bit_mask) | ~bit_mask));
  } else {
    printf(" %4d ", (number & bit_mask));
  }
  printf("\n");
}

void number_conversions() {
  int bits = 8;
  printf("Converting numbers\n");
  print_conversions(0b01001101, bits);
  print_conversions(0xA1,       bits);
  print_conversions(254,        bits);
  print_conversions(-17,        bits);
  print_conversions(255,        bits);
}


void problem_2_12_a(int x) {
  int bit_mask = (1 << 8)-1;
  printf(" a) 0x%X\n", x & bit_mask);
}

void problem_2_12_b(int x) {
  int bit_mask = (1 << 8)-1;
  int complemented = (~x & ~bit_mask) | (x & bit_mask);
  printf(" b) 0x%X\n", complemented);
}

void problem_2_12_c(int x) {
  int bit_mask = (1 << 8)-1;
  printf(" c) 0x%X\n", x | bit_mask);
}

void bit_masking() {
  int x = 0x87654321;
  printf("Bit Masking (Practice Problem 2.12)\n");
  printf("   w = 32-bit,  x = 0x%X\n", x);
  problem_2_12_a(x);
  problem_2_12_b(x);
  problem_2_12_c(x);
}
void bit_level_operations() {
  int x = 0xA8;
  int y = 24;
  int bits = 8;
  unsigned int bit_mask = (1 << bits) - 1;

  printf("Bit Level Operations (Practice Problem 2.14)\n");
  printf("   x = 0x%X,   y = 0x%X,   bits = %d\n",x,y,bits);


  printf(" x & y   = 0x%X\n", ( (x & y)   & bit_mask) );
  printf(" x | y   = 0x%X\n", ( (x | y)   & bit_mask) );
  printf(" x ^ y   = 0x%X\n", ( (x ^ y)   & bit_mask) );
  printf(" ~x | ~y = 0x%X\n", ( (~x | ~y) & bit_mask) );
  printf(" y << 2  = 0x%X\n", ( (y << 2)  & bit_mask) );
}

void problem_2_17() {
  printf("\nProblem 2.17 (4-bit two's complement conversions)\n");
  print_conversions( 0xE, 4);
  print_conversions( 0x0, 4);
  print_conversions( 0x5, 4);
  print_conversions( 0x8, 4);
  print_conversions( 0xD, 4);
  print_conversions( 0xF, 4);
}

void problem_2_18() {
  printf("\nProblem 2.18 (16-bit two's complement conversions)\n");
  print_conversions( 0x1B8, 16);
  print_conversions( 0x14, 16);
  print_conversions( 0xFE58, 16);
  print_conversions( 0xFE74, 16);
  print_conversions( 0x44, 16);
  print_conversions( 0xFEC8, 16);
  print_conversions( 0x10, 16);
  print_conversions( 0xC, 16);
  print_conversions( 0xFEEC, 16);
}
int main() {
  unsigned int bits = 8;

  printf("%s\n", to_binary(-17,         bits));
  printf("%s\n", to_binary(0x69 & 0x55, bits));
  printf("%s\n", to_binary(~0xF, bits));

  bit_level_operations();
  number_conversions();
  bit_masking();

  problem_2_17();
  problem_2_18();

  return 0;
}
