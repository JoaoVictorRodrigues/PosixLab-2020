//#include "macros.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void green() {
  printf("\033[0;32m");
}

void reset () {
  printf("\033[0m");
}

void magenta () {
  printf("\033[0;35m");
}

int main(int argc, char *argv[]) {

    pid_t son, wpid;
    int pass_count = 0;
    int status = 0;
    int size = sizeof(all_tests)/sizeof(test_data);
    int count = 0;

    if(argc == 1){
        
        printf("Running %d tests:\n", size);
        printf("=====================\n\n");
        for (int i = 0; i < size; i++) {
            son = fork();
            if(son == 0 ){
                if (all_tests[i].function() >= 0) {
                    green();
                    printf("%s: [PASS]\n", all_tests[i].name);
                    count = 1;
                    reset();
                };
                break;
            };
        };
        reset();
        if(son == 0 ){
            return count;
        }

        
        while ((wpid = wait(&status)) > 0){
            int id = wpid - getpid();
            magenta();
            if (WIFSIGNALED(status)) printf("test%d: [Erro] %s\n",id,strsignal(WTERMSIG(status)));
            pass_count += WEXITSTATUS(status);
            reset();
            
        };
        
        printf("\n\n=====================\n");
        printf("%d/%d tests passed\n", pass_count,size );

    }else{

        //int size = sizeof(all_tests)/sizeof(test_data);
        printf("Running %d test:\n", size);
        printf("=====================\n\n");
        for (int i = 0; i < size; i++) {
            if(strcmp(all_tests[i].name,argv[1])== 0){
                if (all_tests[i].function() >= 0) {
                    green();
                    printf("%s: [PASS]\n", all_tests[i].name);
                    pass_count++;
                    reset();
                };
            }
        }
        reset();
        printf("\n\n=====================\n");
        printf("%d/%d tests passed\n\n", pass_count, (argc) - 1 );
        return 0; 
    }
    
    
}
