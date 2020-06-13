#include <stdio.h>

typedef int (*test_func)();

typedef struct {
    char name[50];
    test_func function;
} test_data;

void red() {
  printf("\033[0;31m");
}
void rese() {
  printf("\033[0m");
}

#define test_printf (printf("%s: ", __func__));printf

#define test_assert(expr, str) { if(!(expr)) {red(); printf("%s: [FAIL] %s in %s:%d\n", __func__, str, __FILE__, __LINE__);reset();return -1;} }

#define TEST(f) {.name=#f, .function=f}

#define test_list test_data all_tests[]

