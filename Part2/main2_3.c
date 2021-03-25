#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

    // 1. Create a child process by forking from the parent process.
    pid_t pid = fork(); 

    if(pid == 0) {
        
        // Child --> Want to make a daemon process out of it.
        
        //Init Daemon: 
        // 2. "Move" process to root directory ('/').
        chdir("/");

        // 3. Change session of the daemon process, so the parent proc and daemon child proc 
        // will not be connected.
        // If Child cannot die so parent cannot die also.
        setsid();

        // 4. Close all I/O chanlles (stdin, stdout, stderr)
        close(stdin);
        close(stdout);
        close(stderr);
        

    } else {
        // Parent
    }



}