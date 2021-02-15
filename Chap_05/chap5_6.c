#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int rc = fork();
    int status;
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        return 1;
    } else if (rc == 0) {
        printf("I am child, PID: %d\n", getpid());
    } else {
        int rc_wait = waitpid(0, &status, WUNTRACED);
        printf("I am your Parent, PID: %d\n", getpid());
        printf("%d", rc_wait);
    }
    return 0;
}
