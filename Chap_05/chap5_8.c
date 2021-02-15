#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pipe(fd);
    int child1 = fork();
    if (child1 < 0) {
        fprintf(stderr, "fork failed\n");
        return 1;
    } else if (child1 == 0) {
        int child2 = fork();
        if (child2 < 0) {
            fprintf(stderr, "fork failed\n");
            return 1;
        } else if (child2 == 0) {
            close(STDOUT_FILENO);
            printf("Hello i am child 2, PID: %d\n", getpid());
            char string[] = "Hello i am child 2 through pipe\n";
            write(fd[1], string, sizeof(string));
            close(fd[1]);
        } else {
            char child2String[50];
            printf("Hello i am child 1, PID: %d\n", getpid());
            read(fd[0], child2String, 50);
            printf(child2String);
            close(fd[0]);
        }
    } else {
        int rc_wait = wait(NULL);
        printf("Hello i am parent, PID: %d\n", getpid());
        printf("%d", rc_wait);
    }
    return 0;
}
