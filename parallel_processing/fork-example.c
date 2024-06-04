#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

int main() {
	pid_t pid;
	pid = fork();

	if (pid < 0) {
		fprintf(stderr, "ERROR: fork failed  with code ", errno);
		return 1;
	}
	else if (pid > 0) {  // PARENT (INITIAL) process, pid is the child's PID:
		printf("PARENT (my pid=%d): child process created with pid=%d\n\n", getpid(), pid);
	}
	else {               // pid==0, executed only by the child process
		printf("CHILD: my pid=%d\n\n", getpid());
	}

	// code outside if-then-else is run by both parent and child

	printf("OUTSIDE IF: my pid=%d\n\n", getpid());
	
	return 0;  // 0 is the "normal" return code in case of no errors
}

		