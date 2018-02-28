#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "answer06.h"

int printNode(List *);
int compar(const char * j, const char * k)
{
	if((j == NULL) || (k == NULL))
	{
		return 1;
	}
	else
	{
		return strcmp(j,k);
	}
}
int main()
{
	List * list = List_createNode("df");
	List * curr = List_createNode("cg");
	curr->next = list;
	list = curr;
	
	List * c = List_sort(list, compar);
	printNode(c);
	List_destroy(c);

	return 0;
}

int printNode(List * list)
{
	while(list != NULL)
	{
		printf("%s \n", list->str);
		list = list->next;
	}
	return 0;
}


