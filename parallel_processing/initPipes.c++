#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main()
{
    // Creating pipe to communicate between processes
    int fd[2];
    if (pipe(fd) == -1)
    {
        return 1;
    }

    // Creating first child within parent
    pid_t child2 = fork();
    if (child2 < 0)
    {
        // Error on child creation
        fprintf(stderr, "Fork Failed");
        return 1;
    }

    if (child2 == 0)
    {
        // In the child2 process
        close(fd[1]);              // Close the write end of the pipe since it is not used
        dup2(fd[0], STDIN_FILENO); // Reading pipe and placing that in input *need to better understand STDIN_FILENO
        close(fd[0]);              // Closing pipe

        execlp("sort", "sort", "-r", "-n", "-k", "5", NULL);
    }

    pid_t child1 = fork();
    if (child1 < 0)
    {
        // Error on child creation
        fprintf(stderr, "Fork Failed");
        return 1;
    }

    if (child1 == 0)
    {
        // In the child1 process
        close(fd[0]);               // Close the read end of the pipe since it is not used
        dup2(fd[1], STDOUT_FILENO); // Takes the output and sends it through the pipe
        close(fd[1]);

        execlp("ps", "ps", "aux", NULL);
    }

    // In the parent process
    close(fd[0]);
    close(fd[1]);

    return 0;
}