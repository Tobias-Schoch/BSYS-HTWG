#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        return 1;
    } else if (rc == 0) {
        //int rc_wait = wait(NULL);
        printf("I am child, PID: %d\n", getpid());
    } else {
        int rc_wait = wait(NULL);
        printf("Back to parent: %d\n", rc_wait);
    }
    return 0;
}
