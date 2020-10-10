/*******************************************************************
Users: Christian Gordon, Brandon Holder, Tahwab Noori, Tyler Cox
Use: Create a Unix shell that runs a series of basic commands.
Create child processes that will execute user inputed commands.
*******************************************************************/
#include <stdio.h>
#include <unistd.h>

#define MAX LINE 80 /* The maximum length command */

/*******************************************************************
Parse function
parses the users inut
*******************************************************************/
void fflush(stdout)
{

}

/*******************************************************************
execvp
parses the users inut
*******************************************************************/
void execvp(array args[], string args)
{

}

/*******************************************************************
Main function
*******************************************************************/
int main(void)
{
	char* args[MAX LINE / 2 + 1]; /* command line arguments */
	int should run = 1; /* flag to determine when to exit program */
	char* token;

	while (should run)
	{	
		printf("osh>");
		scanf("%s", args);

		//Call parse function
		fflush(stdout);

		/**
		 * After reading user input, the steps are:
		 * (1) fork a child process using fork()
		 * (2) the child process will invoke execvp()
		 * (3) parent will invoke wait()
		 */

	}
	return 0;
}