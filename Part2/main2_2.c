#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>

#define STACK_SIZE 10000

int foo(char *str) {
    printf("Hello from %s\n", str);
    sleep(5);
    exit(1);
}

int handler() {
    foo("Child process");
}

int main() {

    char stack[STACK_SIZE + 1];
    
    int proc1 = clone(handler, stack + STACK_SIZE, CLONE_PARENT, 0);
    int proc2 = clone(handler, stack + STACK_SIZE, CLONE_PARENT, 0);

    foo("Parent process");

    return 0;
}