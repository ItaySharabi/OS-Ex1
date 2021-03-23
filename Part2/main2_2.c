#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sched.h>

void foo(const char *pid) {

    for(int i = 0; i < 10; i++) {
        printf("Hello from %s\n", pid);
        sleep(1);
    }
}

int main() {

    fork();
    fork();
    fork();
    foo("3");

    return 0;
}