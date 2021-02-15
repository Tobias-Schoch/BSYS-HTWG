#include <unistd.h>
#include <stdio.h>

int main() {
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        return 1;
    } else if (rc == 0) {
        close(STDOUT_FILENO);
        printf("Hello i am child\n");
    } else {
        printf("Hello i am parent\n");
    }
    return 0;
}
