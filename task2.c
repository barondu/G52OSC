#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define NUMBER_OF_PROCESSES 4

int main() {
	pid_t pid = 0;
	for(int i=0; i<NUMBER_OF_PROCESSES; i++) {
		pid = fork();
		if(pid < 0) {
			printf("Could not create process\n");
			exit(1);
		} else if(pid == 0) {
			sleep(1);
			printf("Hello from child %d process with PID: %d\n",i,getpid());
			exit(1);
		} else if(pid > 0) {
			printf("Hello from parent %d process with PID: %d\n",i,getpid());
		}
	}
	
	pid = fork();
	if (pid < 0)
	{
		printf("Could not create process\n");
	}
	else if (pid == 0)
	{
		 execl("/bin/ps", "ps", "l", 0);
	}
}