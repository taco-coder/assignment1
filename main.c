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
	char args[MAX_LINE / 2 + 1]; /* command line arguments */
	char *argument_list[3];

	int should_run = 1; /* flag to determine when to exit program */
	char *token;
	int status_code = 0;
	int i = 0;

	while (should_run)
	{
		printf("osh>");
		//captures entire string from input
		fgets(args, MAX_LINE / 2 + 1, stdin);

		//breaks up string into individual words every space
		token = strtok(args, " ");

		if (strcmp(args, "exit\n") == 0)
		{
			printf("Exitting...");
			return 0;
		}
		printf("%s\n", args);
		//parse the string
		while (token != NULL)
		{
			argument_list[i] = token;

			token = strtok(NULL, " ");
			i++;
		}
		argument_list[2] = NULL;

		if (fork() == 0)
		{

			// Newly spawned child Process. This will be taken over by "ls -l"
			status_code = execvp(argument_list[0], argument_list);

			if (status_code == -1)
			{
				printf("Terminated Incorrectly\n");
				return 1;
			}
		}
		else
		{
			wait(NULL);
		}
		fflush(stdout);
	}
	return 0;
}