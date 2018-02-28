#include <stdio.h>
#include <stdlib.h>
#ifndef PA09_H
#define PA09_H

typedef struct nd
{
	struct nd * next;
	int index;
	int value;
} Node;

//The following functions are for setting up the linked list. They are completed for you.

/* 
 * Allocates memory for a node and initializes it's attributes.
 */

Node * Node_construct(int val, int index);

/*
 * Inserts node into the list in queue style, allocates heap memory for it, and initializes it.
 * The first to be inserted is the head, second is after the head, etc. 
 */

Node * List_insert ( Node * head , int val );

/* 
 * Frees all heap memory associated with the list
 */

void List_destroy ( Node * head );


/*
 * Prints the list in "[index1]:value1 [index2]:value2 [index3]:value3..." format for each node.
 */

void List_print ( Node * head );


//The below functions are for you to complete


/* 
 * Computes the length of the passed linked list and returns it as an integer.
 * An empty linked list (head==NULL) has a length of zero.
 */

int List_length(Node * head);

/*
 * Given the head of a list, swaps the value attributes at the two nodes with the given indices
 * Returns EXIT_SUCCESS if the swap was successful, otherwise it returns EXIT_FAILURE.
 * You should check to make sure the indices are valid (non-negative and not greater than or equal to the list length)
 * and that index1 is not greater than index2.
 *
 * NOTE: You don't need to swap the nodes themselves, just their value attributes.
 */

int List_swap(Node * head, int index1, int index2);

/*
 * Given the head of a list, finds and returns the value of the node in the list with
 * the given index value. Should return -1 if the index is invalid or not found.
 */

int List_read(Node * head, int index);

/*
 * Given the head of a list, writes the value val to the node with the
 * the given index value. Should return EXIT_SUCCESS if the write was successful
 * and EXIT_FAILURE if the index is invalid or not found.
 */

int List_write(Node * head, int index, int val);

/* 
 * Given the head of a list and it's length, sort the linked list using 
 * the quicksort algorithm. It should return the head of the list.
 * It's a good idea to use a helper function to recursively perform the algorithm.
 * Look at the README and Lecture_07_05 to see how the algorithm works and look  
 * at Code07_01 for a quicksort implementation with arrays. You can use the other 
 * functions implemented in this assignment to help you complete this one.
 */

Node * List_qsort(Node * head, int length);


/* 
 * Reads a linked list from a file in text format and creates 
 * the specified linked list structure in heap memory.
 * The file contains the nodes in order (the first line
 * is the first node and the last line is the last node)
 * Each line has the value stored at that node.
 * If the read was successful, should return a pointer to the
 * head of the list. Otherwise should return NULL.
 */

Node * List_readFromTextFile(char * filename);

/* 
 * Writes a linked list to a file in text format.
 * You should use the format described above where the nth line
 * of the file contains the value of the nth node.
 * The function should return EXIT_SUCCESS if the write was successful
 * and EXIT_FAILURE otherwise.
 */

int List_writeToTextFile(Node * head, char * filename);

/* 
 * Reads a linked list from a file in binary format and creates 
 * the specified linked list structure in heap memory.
 * The nodes are read from first to last (the first node 
 * read is the first node in the list).
 * If the read was successful, should return a pointer to the
 * head of the list. Otherwise should return NULL.
 */

Node * List_readFromBinaryFile(char * filename);

/*
 * Writes a linked list to a file in binary format.
 * Write the nodes to the file in order from first node to last.
 * The function should return EXIT_SUCCESS if the write was successful
 * and EXIT_FAILURE otherwise.
 */

int List_writeToBinaryFile(Node * head, char * filename);


#endif
