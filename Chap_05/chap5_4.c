#define _DEFAULT_SOURCE
#define _GNU_SOURCE
#include <unistd.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
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
            // child 2
            printf("CHILD 2: execl\n");
            execl("/bin/ls", "ls", (char*) NULL);
        } else {
            // child 1
            wait(NULL);
            int child3 = fork();
            if (child3 < 0) {
                fprintf(stderr, "fork failed\n");
                return 1;
            } else if (child3 == 0) {
                // child 3
                char *environment[4];
                environment[0] = "SHELL=/bin/csh";
                environment[1] = "LOGNAME=heino";
                environment[2] = "OSTYPE=LiNuX";
                environment[3] = NULL;
                printf("CHILD 3: execle\n");
                execle("/bin/ls", "ls", NULL, environment);
            } else {
                // child 1
                wait(NULL);
                int child4 = fork();
                if (child4 < 0) {
                    fprintf(stderr, "fork failed\n");
                    return 1;
                } else if (child4 == 0) {
                    // child 4
                    printf("CHILD 4: execlp\n");
                    execlp("ls", "ls", NULL);
                } else {
                    // child 1
                    wait(NULL);
                    int child5 = fork();
                    if (child5 < 0) {
                        fprintf(stderr, "fork failed\n");
                        return 1;
                    } else if (child5 == 0) {
                        // child5
                        char *myargs[2];
                        myargs[0] = "/bin/ls";
                        myargs[1] = NULL;
                        printf("CHILD 5: execv\n");
                        execv(myargs[0], myargs);
                    } else {
                        wait(NULL);
                        int child6 = fork();
                        if (child6 < 0) {
                            fprintf(stderr, "fork failed\n");
                            return 1;
                        } else if (child6 == 0) {
                            //child6
                            printf("CHILD 6: execvp\n");
                            char *myargs[2];
                            myargs[0] = "ls";
                            myargs[1] = NULL;
                            execvp(myargs[0], myargs);
                        } else {
                            wait(NULL);
                            printf("CHILD 1: execvpe\n");
                            char *myargs[2];
                            myargs[0] = "ls";
                            myargs[1] = NULL;
                            char *environment[4];
                            environment[0] = "SHELL=/bin/csh";
                            environment[1] = "LOGNAME=heino";
                            environment[2] = "OSTYPE=LiNuX";
                            environment[3] = NULL;
                            execvpe(myargs[0], myargs, environment);
                        }
                    }
                }
            }
        }
    } else {
        int rc_wait = wait(NULL);
        printf("WAIT PARENT PID: %d", rc_wait);
    }
    return 0;
}
