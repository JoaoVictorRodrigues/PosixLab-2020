#include "mintest/macros.h"
#include <unistd.h>


int test1() {
    test_printf("Friendly Test!\n");
    return 0;
}

int test2() {
    test_assert(1 == 0, "This always fails!");
    test_assert(1 == 1, "Neither this.");
    printf("This never runs!\n");
    return 0;
}

int test3() {
    test_printf("True condition\n");
    test_assert(1 == 1, "This always succeeds");
    return 0;
}
int test4() {
    test_assert(1 % 0, "Divisão por zero\n");
    return 0;
}
int test5() {
    alarm(5);
    test_printf("Loop infinito");

    while (1){
    }
    return 0;
}
int test6(){
    int i,j, k; 
    for(i = 0; i<10000; i++){
        for(j = i; j<10000; j++){
            for ( k = j; k < 3000; k++)
            {
        
            }
        }
    }
    return 0;
}
int test7(){
    int i;
    for(i = 0; i< 100; i++){
        test_printf("The cake is a lie\n");
    }
    return 0;
}
int test8(){
    test_printf("Teste Rapido\n");
    test_assert(1>0, "Teste Rapido");
    sleep(5);
    test_printf("Teste Lento\n");
    test_assert(1+1 == 2, "Teste Lento");
    return 0;

}
int test9(){
    alarm(5);
    int *n = NULL;
    *n = 10;
    test_assert(2>1, "Falha de segmentação");
    return 0;

}

test_list = { TEST(test1), TEST(test2), TEST(test3), TEST(test4), TEST(test5), TEST(test6), TEST(test7), TEST(test8), TEST(test9) };

#include "mintest/runner.h"
