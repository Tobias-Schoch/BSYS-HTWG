#include <sys/types.h>
#include <sys/fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pid = getpid();
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        return 1;
    } else if (rc == 0) {
        printf("hello\n");
        kill(pid, SIGCONT);
    } else {
        kill(pid, SIGSTOP);
        printf("goodbye\n");
    }
    return 0;
}
