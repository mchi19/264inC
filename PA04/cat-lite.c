#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char ** argv)
{
	int i;
	int j;
	int temp;
	FILE * fptr;
	int x = 0; //help indicator

	void helpfunc() //--help indicator message
	{
		printf("Usages: cat-lite [--help][FILE]...\nWith no FILE, or when FILE is -, read standard input.\n\nExamples:\ncat-lite README    Print the file README to standard output.\ncat-lite f - g     Print f's contents, then standard input, then g's contents.\ncat-lite           Copy standard input to standard output.\n");
	}
	if(argc < 2) //if there are no arguments being passed
	{
		while((temp = fgetc(stdin)) != EOF)
		{
			fputc(temp, stdout);
		}
		return EXIT_SUCCESS;
	}
	for(i = 1; i < argc; i++)
	{
		if(strcmp(argv[i], "--help") == 0)
		{
			x = 1;
			i = argc;
		}
	}	
	for(j = 1; j < argc; j++)
	{
		if(x == 1)
		{
			helpfunc();
			return EXIT_SUCCESS;
		}
		else //if(x == 0)
		{
			if(strcmp(argv[j], "-") == 0)
			{
				while((temp = fgetc(stdin)) != EOF)
				{
					fputc(temp, stdout);
				}
			}
			else
			{
				fptr = fopen(argv[j], "r");
				if(fptr == NULL)
				{
					fprintf(stderr, "cat-lite cannot open %s\n", argv[j]);
					return EXIT_FAILURE;
				}
				else
				{
					while((temp = fgetc(fptr)) != EOF)
					{	
						fputc(temp, stdout);	
					}
					if(fptr)
					{
						fclose(fptr);
					}
				}
			}
		}
	}
	return 0;
}
