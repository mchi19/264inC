#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer07.h"

List * List_createNode(const char * str)
{
	List * node = malloc(sizeof(List));
	if(str == NULL)
	{
		node->str = NULL;
	}
	else
	{
		node->str = strdup(str);
	}
	node->next = NULL;

	return node;
}

void List_destroy(List * list)
{
	if(list == NULL)
	{
		return;
	}
	List_destroy(list->next);
	free(list->str);
	free(list);
	return;
}

int List_length(List * list)
{
	int len = 0;
	List * temp = list;
	while(temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	return len;
}

List * List_merge(List * lhs, List * rhs, int (*compar)(const char *, const char*))
{
	List * newlist = NULL;
	List * temp = NULL;
	int cmp = 0;
	if((lhs == NULL) && (rhs == NULL))
	{
		return newlist;
	}
	else if(lhs == NULL)
	{
		newlist = rhs;
		return newlist;
	}
	else if(rhs == NULL)
	{
		newlist = lhs;
		return newlist;
	}
	cmp = compar(lhs->str, rhs->str);
	if(cmp <= 0)
	{
		newlist = lhs;
		temp = lhs;
		lhs = lhs->next;
		temp->next = NULL;
	}
	else //if cmp > 0
	{
		newlist = rhs;
		temp = rhs;
		rhs = rhs->next;
		temp->next = NULL;
	}
	while((lhs != NULL) && (rhs != NULL))
	{
		cmp = compar(lhs->str, rhs->str);
		if(cmp <= 0)
		{
			temp->next = lhs;
			lhs = lhs->next;
			temp = temp->next;
			temp->next = NULL;
		}
		else
		{
			temp->next = rhs;
			rhs = rhs->next;
			temp = temp->next;
			temp->next = NULL;
		}
	}
	if(lhs == NULL)
	{
		temp->next = rhs;
	}
	else if(lhs != NULL)
	{
		temp->next = lhs;
	}
	else if(rhs == NULL)
	{
		temp->next = lhs;
	}
	else if(rhs != NULL)
	{
		temp->next = rhs;
	}
	return newlist;
}	

List * List_sort(List * list, int (*compar)(const char *, const char *))
{
	List * srtlist = NULL; //sorted list
	int len1 = List_length(list);
	int len2 = len1/2; //to find middle of linked list length
	int i = 0;
	List * lhs = NULL;
	List * rhs = NULL;
	lhs = list;
	if(len1 < 2) //if len1 is less than 0 or 1
	{
		return list;
	}
	for(i = 1; i < len2; i++)
	{
		list = list->next;
	}
	rhs = list->next; //copy right segment to rhs
	list->next = NULL;
	lhs = List_sort(lhs, compar);
	rhs = List_sort(rhs, compar);
	srtlist = List_merge(lhs, rhs, compar);
	return srtlist;
}

