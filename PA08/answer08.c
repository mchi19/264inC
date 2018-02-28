#include "answer08.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0


/* charcmp is used to to compare chars for isValidState(...)
 * This function is supplied to you.
 */


int charcmp(const void * a, const void * b)
{
    return *((char*)a) - *((char*)b);
}

/* This function is supplied to you.*/


int isValidState(const char * state)
{
    int len = strlen(state);
    if(len != 16) return FALSE;
    char buffer[17];
    strcpy(buffer, state);
    qsort(buffer, len, sizeof(char), charcmp);
    const char * valid = "-123456789ABCDEF";
    if(strcmp(valid, buffer) == 0)
	return TRUE;
    return FALSE;
}

/* This function is supplied to you.*/

int isValidMoveList(const char * moves)
{
    int len = strlen(moves);
    int i;
    for(i = 0; i <  len; ++i)
	if(moves[i] != 'R' && moves[i] != 'L' && 
	   moves[i] != 'U' && moves[i] != 'D')
	    return FALSE;
    return TRUE;
}

/* This function is supplied to you.*/

void printPuzzle(const char * state)
{
    int row, col;
    for(row = 0; row < SIDELENGTH; ++row) {
	for(col = 0; col < SIDELENGTH; ++col) {
	    printf(" %c", state[row*SIDELENGTH + col]);
	}
	printf("\n");
    }
}

/* This function is supplied to you.*/


int move(char * state, char m)
{
    int dx = 0;
    int dy = 0;
    switch(m) {
    case 'U': dy = -1; break;
    case 'D': dy = 1; break;
    case 'L': dx = -1; break;
    case 'R': dx = 1; break;
    default:
	fprintf(stderr, "Invalid move '%c'!\n", m);
	return FALSE;
    }
    char * strpos = strstr(state, "-");
    if(strpos == NULL) {
	fprintf(stderr, "Invalid state '%s'!\n", state);
	return FALSE;
    }
    int pos = strpos - state;
    int row = pos / SIDELENGTH;
    int col = pos % SIDELENGTH;
    if(row + dy < 0 || row + dy >= SIDELENGTH)
	return FALSE;
    if(col + dx < 0 || col + dx >= SIDELENGTH)
	return FALSE;

    // Now we know we have a valid move...
    int target_pos = (row+dy)*SIDELENGTH + (col+dx);

    // So swap 'pos' with 'target_pos'
    state[pos] = state[target_pos];
    state[target_pos] = '-';

    return TRUE;
}

/* This function is supplied to you.*/


void processMoveList(char * state, const char * movelist)
{
    int valid = TRUE;
    int ind = 0;
    int movelist_len = strlen(movelist);
    for(ind = 0; ind < movelist_len && valid; ++ind) 
	{
		if(!move(state, movelist[ind])) 
		{
			valid = FALSE;
		} 
    }
	    
    if(!valid) {
		printf("I\n");
    } 
	else {
		printf("%s\n", state);
    }
}

//You will need to compMoveTree * lete the following functions (except for solve(...) and MoveTree_print(...))

MoveTree * MoveTree_create(const char * state, const char * moves)
{	
	MoveTree * node = malloc(sizeof(MoveTree));
	node->state = strdup(state);
	node->moves = strdup(moves);
	node->left = NULL;
	node->right = NULL;
	return node;
}

void MoveTree_destroy(MoveTree * node)
{
	if(node == NULL)
	{
		return;
	}
	else //else node != NULL
	{
		MoveTree_destroy(node->left);
		MoveTree_destroy(node->right);
		free(node->state);
		free(node->moves);
		free(node);
	}
}

MoveTree * MoveTree_insert(MoveTree * node, const char * state, const char * moves)
{
	int check1;
	int len1;
	int len2;
	if(node == NULL)
	{
		return MoveTree_create(state, moves);
	}
	else
	{
		check1 = strcmp(node->state, state);
		if(check1 < 0) //traverse left subtree
		{
			node->left = MoveTree_insert(node->left, state, moves);
		}
		else if(check1 > 0) //traverse right subtree
		{
			node->right = MoveTree_insert(node->right, state, moves);
		}
		else if(check1 == 0)
		{
			len1 = strlen(node->moves);
			len2 = strlen(moves);
			if(len1 > len2)
			{
				strcpy(node->moves, moves);
			}
		}
	}
  	return node; 
}

MoveTree * MoveTree_find(MoveTree * node, const char * state)
{
	int check;
	if(state == NULL) //nothing in state
	{
		return NULL;
	}
	if(node == NULL) //nothing found in node
	{
		return NULL;
	}
	check = strcmp(node->state, state);
	if(check == 0) //name found in node
	{
		return node;
	}
	else
	{
		if(check < 0)
		{
			node = MoveTree_find(node->left, state);
		}
		else if(check > 0)//if check > 0
		{
			node = MoveTree_find(node->right, state);
		}
		return node;
	}
}

/**
 * Print the moves in a move-tree.
 * This function is supplied to you.
 */
void MoveTree_print(MoveTree * node)
{
    if(node == NULL)
		return;
    printf("%s\n", node -> state);
    MoveTree_print(node -> left);
    MoveTree_print(node -> right);
}

/*Helper function for generateAll, you do *NOT* need to use this function but you may find it useful*/
void generateAllHelper(MoveTree * root, int n_moves, const char * state, char * movelist, int ind)
{    
	if(root == NULL)
	{
		return;
	}
	if(ind == n_moves)
	{
		return;
	}
	char * pm = "UDLR"; //possible moves Up, Down, Left, Right
	int len_pm = strlen(pm); //length of possible moves
	int i; //iterative variable
	char * dup_state; //duplicate state
	char m; //variable to store a single move
	int x; //temp variable
	for(i = 0; i < len_pm; i++)
	{
		dup_state = strdup(state);
		m = pm[i]; //what is 'm' supposed to be?
		x = move(dup_state, m);
		if(x == 1) //move works
		{
			movelist[ind] = m;
			movelist[ind + 1] = '\0';
			MoveTree * node = MoveTree_insert(root, dup_state, movelist);	
			generateAllHelper(node, n_moves, dup_state, movelist, ind + 1);
		}
		free(dup_state);
	}
	return;
}

MoveTree * generateAll(char * state, int n_moves)
{ 
	int ind = 0;
	char * movelist = malloc(sizeof(char) * (n_moves + 1));
	movelist[0] = '\0'; //null byte added to end of movelist
	MoveTree * node = MoveTree_create(state, "");
	generateAllHelper(node, n_moves, state, movelist, ind);
	free(movelist);
	return node;
}

/* This function is supplied to you.*/

char * solve(char * state)
{
    MoveTree * tree = generateAll(state, MAX_SEARCH_DEPTH);
    MoveTree * answer = MoveTree_find(tree, FINAL_STATE);
    char * movelist = NULL;
    if(answer != NULL){
		movelist = strdup(answer -> moves);
	}
    MoveTree_destroy(tree);
    return movelist;
}

