/*******************************************************************
Users: Christian Gordon, Brandon Holder, Tahwab Noori, Tyler Cox
Use: Create a Unix shell that runs a series of basic commands.
Create child processes that will execute user inputed commands.
*******************************************************************/
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE 80 /* The maximum length command */
/*******************************************************************
Main function
*******************************************************************/
int main(void)
{
	char *args[MAX_LINE / 2 + 1]; /* command line arguments */
	int should_run = 1;			  /* flag to determine when to exit program */
	const char *token;
	int status_code = 0;
	
	while (should_run)
	{
		printf("osh>");
		scanf("%c", args);

		token = strtok(args, " ");

		if (fork() == 0)
		{
			printf("forked\n");
			// Newly spawned child Process. This will be taken over by "ls -l"
			status_code = execvp(token[0], token);
			printf("post status_code\n");
			printf("%d\n", &status_code);
			if (status_code == -1)
			{
				printf("Terminated Incorrectly\n");
				return 1;
			}
		}
		else
		{
			// Old Parent process. The C program will come here
			wait(NULL);
			printf("This line will be printed\n");
		}
		//fflush(stdout);
	}
	return 0;
}