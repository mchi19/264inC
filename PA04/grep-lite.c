#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define FAIL 2

int main(int argc, char ** argv)
{
	int i;
	int v = 0; //invertmatch indicator
	int n = 0; //line number indicator
	int q = 0; //quiet indicator
	int j = argc - 1;
	char *pattern; //pattern
	pattern = argv[j];
	int m = 0; //match indicator
	
	void helpfunc()
	{
		printf("Usage: grep-lite [OPTION]... PATTERN\nSearch for PATTERN in standard input. PATTERN is a \nstring. grep-lite will search standard input line by\nline, and (by default) print out those lines which\ncontain pattern as a substring.\n\n-v, --invert-match     print non-matching lines\n-n, --line-number      print linenumbers with output\n-q, --quiet            suppress all output\n\nExit status is 0 if any line is selected, 1 otherwise;\nif any error occures, then the exit status is 2.\n");
	}
	
	if(argc < 2)
	{
		fprintf(stderr, "Error: no arguments inputted.\n");
		return FAIL;
	}
	
	for(i = 1; i < argc; i++)
	{
		if(strcmp(argv[i], "--help") == 0)
		{
			helpfunc(); //#1
			return EXIT_SUCCESS;
		}
		else if(strcmp(argv[i], "-v") == 0)
		{
			v = 1;	
		}
		else if(strcmp(argv[i], "--invert-match") == 0)
		{
			v = 1;
		}
		else if(strcmp(argv[i], "-n") == 0)
		{
			n = 1;
		}
		else if(strcmp(argv[i], "--line-number") == 0)
		{
			n = 1;
		}
		else if(strcmp(argv[i], "-q") == 0)
		{
			q = 1;
		}
		else if(strcmp(argv[i], "--quiet") == 0)
		{
			q = 1;
		}
		else //if bogus input //#2
		{
			fprintf(stderr, "Error: invalid input.\n");
			return FAIL;
		}
	}

	if(pattern[0] == '-') //#3
	{
		fprintf(stderr, "Error: invalid input, pattern cannot begin with '-'.\n");
		return FAIL;
	}
	
	if(m == 1)//if any matches found #9
	{
		return 0;	
	}
	else //if no matches found
	{
		return 1;
	}
}
