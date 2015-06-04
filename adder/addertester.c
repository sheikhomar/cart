#include <stdlib.h>
#include <assert.h>

// int adder(int *a, int *b);

int adder(int *a, int *b) {
  int sum = *a + *b;

  if (*a > 0 && *b > 0 && sum < 0)
    return 0;

  if (*a < 0 && *b < 0 && sum > 0)
    return 0;
  
  *a = sum;
  return 1;
}

int main() {
    int a, b;
    int retval;

    a = 1000;
    b = 500;
    retval = adder(&a, &b);
    assert(retval == 1);
    assert(a == 1500);
    
    a = 500;
    b = -1000;
    retval = adder(&a, &b);
    assert(retval == 1);
    assert(a == -500);

    a = -2000000000;
    b = -2000000000;
    retval = adder(&a, &b);
    assert(retval == 0);
    assert(a == -2000000000);

    a = 2000000000;
    b = 2000000000;
    retval = adder(&a, &b);
    assert(retval == 0);
    assert(a == 2000000000);

    a = 2000000000;
    b = 42;
    retval = adder(&a, &b);
    assert(retval == 1);
    assert(a == 2000000042);

    a = 2000000001;
    b = 42;
    retval = adder(&a, &b);
    assert(retval == 1); // Should return 1 here?
    assert(a == 2000000043);

    a = 1000000000;
    b = 1000000000;
    retval = adder(&a, &b);
    assert(retval == 1);
    assert(a == 2000000000);

    return 0;
}
