#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>


int main() {

    char *args[] = {NULL};


    pid_t pid = fork();

    if (pid == 0) {
        printf("\nTask: 1\n");
        execv("./main2_2", args);
        exit(1);
    } else {

        pid = fork();

        if(pid == 0) {
            execv("./main2_3", args);
            printf("pid2_3: %d\n", getpid());
            exit(1);

        } else {
            pid = fork();

            if(pid == 0) {
                execv("./main2_1", args);
                printf("pid2_1: %d\n", getpid()); 
                exit(1);
                
            }
        }
    }

    


    
    return 0;
}