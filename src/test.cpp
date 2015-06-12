
#include "test.h"
#include <stdio.h>
#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif

int test() { return 1; }

void check(const int in, int *x, int *y) {
  std::cout << "Result" << std::endl;
  *x = in * 2;
  *y = in * 4;
}

#ifdef __cplusplus
} /* extern "C" */
#endif
