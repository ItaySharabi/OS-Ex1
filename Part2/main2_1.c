#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sched.h>
// main process:

void foo(const char *pid) {

    for(int i = 0; i < 10; i++) {
        printf("Hello from %s\n", pid);
        sleep(10);
    }
}


int main() {

    printf("----------------- TASK 1 -----------------\n");

    pid_t pid = fork(); //Split into 2 Threads, Main -> Child

    if(pid == 0) {
        // We're inside child process
        foo("Task 1 Child");

        pid = fork(); // Split into 3 Threads: Main -> Child --> GrandChild


        if(pid == 0) {
            // We're inside grandchild 
            
            foo("Task 1 Grandchild");
            exit(1);
            return 0;
        }
    } else if(pid > 0){
        // We're inside parent process

        foo("Task 1 Parent");
        // foo("Parent");
        exit(1);
    }

    sleep(55);
    printf("Task 1 finished!\n");
    exit(1);
    return 0;
}