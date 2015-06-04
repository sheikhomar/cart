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

  printf("Showing conversion for number: %d\n", number);
  printf(" %s ", to_binary(number, bits));
  printf(" 0x%X ", (number & bit_mask));
  printf(" %d ", (unsigned_number & bit_mask));
  if (unsigned_number >= max_unsigned) {
    printf(" %d ", ((number & bit_mask) | ~bit_mask));
  } else {
    printf(" %d ", (number & bit_mask));
  }
  printf("\n");
}


int main() {
  unsigned int x = 0xa8;
  unsigned int y = 24;
  unsigned int bits = 8;
  unsigned int bit_mask = (1 << bits) - 1;

  printf("x & y   = 0x%X\n", ( (x & y)   & bit_mask) );
  printf("x | y   = 0x%X\n", ( (x | y)   & bit_mask) );
  printf("x ^ y   = 0x%X\n", ( (x ^ y)   & bit_mask) );
  printf("~x | ~y = 0x%X\n", ( (~x | ~y) & bit_mask) );
  printf("y << 2  = 0x%X\n", ( (y << 2)  & bit_mask) );

  printf("%s\n", to_binary(-17,         bits));
  printf("%s\n", to_binary(0x69 & 0x55, bits));
  printf("%s\n", to_binary(~0xF, bits));

  print_conversions(0b01001101, bits);
  print_conversions(0xA1,       bits);
  print_conversions(254,        bits);
  print_conversions(-17,        bits);
  print_conversions(255,        bits);

  printf("\n\n\n");
  printf("%s\n", to_binary(0b001 << 7, 8));

  printf("\n\n\n");
  printf("%s\n", to_binary((1 << 8)-1, 16));

  return 0; 
}
