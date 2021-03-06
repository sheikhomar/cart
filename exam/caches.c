#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct multi_line_cache {
  int address_bit_count;
  int line_count;
  int set_count;
  int block_size;
  int size;
  int s;
  int b;
  int t;
} MultiLineCache;

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

int calc_bits(int x) {
  int result = 0;
  while (x >>= 1) result++;
  return result;
}

int cache_size(MultiLineCache *cache) {
  return cache->line_count * cache->set_count * cache->block_size;
}

void cache_update(MultiLineCache *cache) {
  cache->size = cache_size(cache);
  cache->s = calc_bits(cache->set_count);
  cache->b = calc_bits(cache->block_size);
  cache->t = cache->address_bit_count - (cache->s + cache->b);
}

void test_address(MultiLineCache *cache, int addr) {
  int block_offset = addr & ((1 << cache->b)-1);
  int set_index = (addr >> cache->b) & ((1 << cache->s)-1);
  int tag = (addr >> (cache->b+cache->s)) & ((1 << cache->t)-1);


  printf("Bit pattern for 0x%X: %s\n", addr, to_binary(addr, cache->address_bit_count));

  printf(" -    Set index (CI): %d (0x%X)\n", set_index, set_index);
  printf(" -    Tag index (CT): %d (0x%X)\n", tag, tag);
  //printf(" - Block offset (CO): %d (0x%X)\n", block_offset, block_offset);
}

void print_info(MultiLineCache *cache) {
  printf("Cache size: %d bytes\n", cache->size);
  printf("Bits for tags:         t = %d\n", cache->t);
  printf("Bits for set index:    s = %d\n", cache->s);
  printf("Bits for block offset: b = %d\n", cache->b);
}

void test_case_1() {
  MultiLineCache c1;
  c1.address_bit_count = 8; // 8-bit system
  c1.line_count = 2; // 2-Way Set Associative cache
  c1.set_count = 4; // 4 cache sets
  c1.block_size = 8; // Block size is 8 bytes

  cache_update(&c1);

  print_info(&c1);

  printf("\n");
  test_address(&c1, 0x64);
  test_address(&c1, 0x70);
  test_address(&c1, 0x00);
  test_address(&c1, 0x01);
  test_address(&c1, 0x78);
  test_address(&c1, 0x02);
  test_address(&c1, 0xA0);
}

void test_case_2() {
  MultiLineCache c1;
  // Cache (S, E, B, m) = (4, 1, 2, 4)
  c1.address_bit_count = 4; // 8-bit system (m)
  c1.line_count = 1; // Direct Map cache (E)
  c1.set_count = 4; // 4 cache sets (S)
  c1.block_size = 2; // Block size is 2 bytes (B)

  cache_update(&c1);

  print_info(&c1);

  printf("\n");
  test_address(&c1,  0);
  test_address(&c1,  1);
  test_address(&c1, 13);
  test_address(&c1,  8);
  test_address(&c1,  0);
}

void test_case_3() {
  MultiLineCache c1;
  // Cache (S, E, B, m) = (4, 1, 2, 4)
  c1.address_bit_count = 13; // 8-bit system (m)
  c1.line_count = 2; // 2-way set associative cache (E)
  c1.set_count = 8; // 8 cache sets (S)
  c1.block_size = 4; // Block size is 4 bytes (B)

  cache_update(&c1);

  print_info(&c1);

  printf("\n");
  test_address(&c1,  0x0E34);
  test_address(&c1,  0x0DD5);
  test_address(&c1,  0x1FE4);
}

void test_case_4() {
  MultiLineCache c1;
  // Cache (S, E, B, m) = (4, 1, 2, 8)
  c1.address_bit_count = 8; // 8-bit system (m=8)
  c1.line_count = 1; // Direct Map cache (E=1)
  c1.set_count = 4; // 4 cache sets (S=4)
  c1.block_size = 8; // Block size is 8 bytes (B=8)

  cache_update(&c1);

  print_info(&c1);

  printf("\n");
  test_address(&c1,  0x64);
  test_address(&c1,  0x70);
  test_address(&c1,  0x00);
  test_address(&c1,  0x01);
  test_address(&c1,  0x78);
  test_address(&c1,  0x02);
  test_address(&c1,  0xA0);
}
int main() {
  //test_case_1();
  //test_case_2();
  //test_case_3();
  test_case_4();

  return 0;
}
