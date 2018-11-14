#include<stdio.h>
#include<stdlib.h>
typedef enum boolean {FALSE,TRUE} Boolean;


/*Pre: Points to the message to be printed
Post: the function prints the message and terminates the program.*/
void Error(const char* s)
{
	fprintf(stderr,"%s\n",s);
	exit(1);
}
