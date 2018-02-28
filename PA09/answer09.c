#include "answer09.h"
#define MAX_SIZE 2001

/* This function has been completed for you */

Node * Node_construct(int val, int ind)
{
	Node * nd = calloc(1,sizeof(Node));
	nd->next = NULL;
	nd->value = val;
	nd->index = ind;
	
	return nd;
}

/* This function has been completed for you */

static Node * List_insertHelper(Node * head , int val, int ind)
{
	if(head == NULL)
	{
		return Node_construct(val,ind);
	}
	head-> next = List_insertHelper(head->next,val,ind+1);
	return head;
}

/* This function has been completed for you */

Node * List_insert ( Node * head , int val)
{
	return List_insertHelper(head,val,0);
} 

/* This function has been completed for you */

void List_destroy ( Node * head )
{
	if(head==NULL) return;
	List_destroy(head->next);
	free(head);
}

/* This function has been completed for you */

void List_print(Node * head)
{
	while(head !=NULL)
	{
		printf("[%d]:%d ",head->index,head->value);
		head = head->next;
	}
	printf("\n");
}

int List_length(Node * head)
{
	int len = 0;
	Node * temp = head;
	while(temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	return len; 
}

int List_swap(Node * head, int index1, int index2)
{
	Node * tnode1; //temp node
	Node * tnode2; //temp node
	int temp; //temp variable
	int len = List_length(head); //length of linked list
	if(head == NULL)
	{
		return EXIT_FAILURE;
	}
	if((index1 < 0) || (index1 >= len))
	{
		return EXIT_FAILURE;
	}
	if((index2 < 0) || (index2 >= len))
	{
		return EXIT_FAILURE;
	}
	if(index1 > index2)
	{
		return EXIT_FAILURE;	  
	}
	while(head->index != index1)
	{
		head = head->next;
	}
	if(head->index == index1)
	{
		tnode1 = head;	
	}
	while(head->index != index2)
	{
		head = head->next;
	}
	if(head->index == index2)
	{
		tnode2 = head;
	}
	
	temp = tnode1->value;
	tnode1->value = tnode2->value;
	tnode2->value = temp;
	return EXIT_SUCCESS;
}

int List_read(Node * head, int index)
{
	int len = List_length(head);
	int i;
	if(head == NULL)
	{
		return EXIT_FAILURE;
	}
	if((index < 0) || (index >= len))
	{
		return EXIT_FAILURE;
	}
	for(i = 0; i < len; i++) 
	{
		if(head->index == index)
		{
			return head->value;
		}
		else
		{
			head = head->next;
		}
	}
	return EXIT_FAILURE;
}

int List_write(Node * head, int index, int val)
{
	int len = List_length(head);
	int i;
	if(head == NULL)
	{
		return EXIT_FAILURE;
	}
	if((index < 0) || (index >= len))
	{
		return EXIT_FAILURE;
	}
	for(i = 0; i < len; i++)
	{
	if(head->index == index)
	{
		head->value = val;
		return head->value;
	}
	else
	{
		head = head->next;
	}
	}
	return EXIT_FAILURE;
}

static void quickSortHelp(Node * head, int first, int last) //modified quicksorthelp function from lecture 07_01 code replace all arr[] with List_read 
{
	if(first >= last)
	{
		return;
	}
	int pivot = List_read(head,first);
	int low = first + 1;
	int high = last;
	while(low < high)
	{
		while((low<last) && (List_read(head,low) <= pivot))
		{
			low++;
		}
		while((first<high) && (List_read(head,high) > pivot))
		{
			high--;
		}
		if(low<high)
		{
			List_swap(head,low, high);
		}
	}
	if(pivot > List_read(head, high))
	{
		List_swap(head,first,high);
	}
	quickSortHelp(head, first, high - 1);
	quickSortHelp(head, low, last);
}

Node * List_qsort(Node * head, int length)
{
	quickSortHelp(head, 0, length - 1);
	return head;
}

Node * List_readFromTextFile(char * filename)
{
	FILE * fptr;
	Node * head = NULL; //temporary node
	int val; //temp value holder
	fptr = fopen(filename, "r");
	if(fptr == NULL)
	{
		return NULL;
	}
	while(fscanf(fptr, "%d",&val) != EOF)
	{	
		head = List_insert(head,val);
	}
	fclose(fptr);
	return head; 
}

int List_writeToTextFile(Node * head, char * filename)
{
	FILE *fptr;
	if(head == NULL)
	{
		return EXIT_FAILURE;
	}
	int len = List_length(head);
	int i;
	fptr = fopen(filename, "w");
	for(i = 0; i < len; i++)
	{
		fprintf(fptr, "%d\n", head->value);
		head = head->next;
	}
	fclose(fptr);
	return EXIT_SUCCESS; 
}

Node * List_readFromBinaryFile(char * filename)
{
	FILE * fptr;
	Node * head = NULL;
	Node * temp = malloc(sizeof(Node)); 
	fptr = fopen(filename, "rb");
	if(fptr == NULL)
	{
		return NULL;
	}
	while(fread(temp, sizeof(Node), 1, fptr) == 1)
	{ 
		head = List_insert(head, temp->value);
	}
	free(temp);
	fclose(fptr);
	return head; 
}

int List_writeToBinaryFile(Node * head, char * filename)
{
	FILE * fptr;
	if(head == NULL)
	{
		return EXIT_FAILURE;
	}
	int len = List_length(head);
	int i;
	fptr = fopen(filename, "wb");
	for(i = 0; i < len; i++)
	{
		fwrite(head, sizeof(Node), 1, fptr);
	}
	fclose(fptr);
	return EXIT_SUCCESS; 
}

