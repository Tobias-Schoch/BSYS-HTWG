#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
    int number = 1000;
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        return 1;
    } else if (rc == 0) {
        fprintf(stdout, "Child number from fork: %d\n", number);
		    number = number + 1;
		    fprintf(stdout, "Child number reassigned: %d\n", number);
    } else {
		    fprintf(stdout, "Parent number from fork: %d\n", number);
        number = number + 2;
        fprintf(stdout, "Parent number reassigned: %d\n", number);
    }
    return 0;
}
