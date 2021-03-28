#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char* argv[], char* envp[])
{
	int status;
	int ecode;
	int signo;
	int child = fork();
	if (child == 0){
		if(strcmp(argv[1],"klaus") == 0){
			exit(EXIT_SUCCESS);
		}

		else if(strcmp(argv[1],"peter") == 0){
			exit(EXIT_FAILURE);
		}

		else if(strcmp(argv[1],"3") == 0){
			printf("Hier könnte ihre Werbung stehen.\n");
			exit(EXIT_FAILURE);
		}

		else if(strcmp(argv[1],"juergen") == 0){
	                int untergang;
			untergang = 20/0;
		}

		else if(strcmp(argv[1],"sauron") == 0){
	                int* pointer = NULL;
			*pointer = 0xdead;
		}

		else {
			printf("Falsche eingabe\n");
			return EXIT_FAILURE;
		}
	
	}

	wait(&status);
	
	if(WIFEXITED(status)){
		ecode = WEXITSTATUS(status);
		printf("%d\n",ecode);
	}

	else if(WIFSIGNALED(status)){
		signo = WTERMSIG(status);
		printf("%d\n",signo);
	}
	
	else{
		printf("else triggered\n");
	}

	return EXIT_SUCCESS;
}
