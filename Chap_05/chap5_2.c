#include <sys/fcntl.h>
#include <unistd.h>
#include <stdio.h>


int main() {
    int file = open("./dont-delete-me.txt", O_CREAT | O_WRONLY | O_TRUNC);
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        return 1;
    } else if (rc == 0) {
        char string[] = "I am from child process\n";
        write(file, string, sizeof(string));
    } else {
        char string[] = "I am from parent process\n";
        write(file, string, sizeof(string));
    }
    close(file);
    return 0;
}
