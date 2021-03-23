#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sched.h>
// main process:

void foo(const char *pid) {

    for(int i = 0; i < 10; i++) {
        printf("Hello from %s\n", pid);
        sleep(1);
    }
}


int main() {

    pid_t pid = fork(); //Split into 2 Threads, Main -> Child

    if(pid == 0) {
        // We're inside child process
        foo("Child");

        pid = fork(); // Split into 3 Threads: Main -> Child --> GrandChild


        if(pid == 0) {
            // We're inside grandchild 

            foo("Grandchild");
            
        }
    } else if(pid > 0){
        // We're inside parent process

        foo("Parent");
        // foo("Parent");
    }


    return 0;
}