#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char * * argv) 
{
	int i;

	for(i = 1; i < argc; i++)
	{
		printf("%s ", argv[i]);
	}
	printf("\n");
	return EXIT_SUCCESS;
}
