#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "answer09.h"

#define MAXLEN 5001

//char * * explode(const char * str, const char * delims, int * arrLen);

BusinessNode * create_node(char * stars, char * name, char * address)
{
	BusinessNode * node = malloc(sizeof(BusinessNode));
	node->name = name;
	node->stars = stars;
	node->address = address;
	node->left = NULL;
	node->right = NULL;
	return node;
}

BusinessNode * tree_insert(BusinessNode * node, BusinessNode * root)
{
	int check; //comparison
	if(node == NULL)
	{
		return root;
	}
	if(root == NULL)
	{
		return node;
	}
	else
	{
		check = strcmp(node->name, root->name);
		if(check == 0)
		{
			return root;
		}
		else if(check <= 0)
		{
			root->left = tree_insert(node, root->left);
		}
		else //if(check > 0)
		{
			root->right = tree_insert(node, root->right);
		}
	}
	return root;
}

BusinessNode * load_tree_from_file(char * filename)
{
  return NULL;
} 

BusinessNode * tree_search_name(char * name, BusinessNode * root)
{
	int check;
	if(name == NULL) //nothing in name
	{
		return NULL;
	}
	if(root == NULL) //name not found in root
	{
		return NULL;
	}
	check = strcmp(name, root->name);
	if(check == 0) //name found in root
	{
		return root;
	}
	else //if name not found in the root
	{
		if(check <= 0)
		{
			root = tree_search_name(name, root->left);	
		}
		else //if(check > 0)
		{
			root = tree_search_name(name, root->right);
		}
		return root;
	}
}

void destroy_tree(BusinessNode * root)
{
	if(root == NULL)
	{
		return;
	}
	else //root != NULL
	{
		destroy_tree(root->left);
		destroy_tree(root->right);
		free(root->name);
		free(root->stars);
		free(root->address);
		free(root);	
	}
	return;
}

/*	
void print_node(Business * node)
{
	int len = strlen(root->name);
	printf("%s", root->name);
	for(int i = 1; i < len; i++)
	{
		printf("=");
	}
	printf("=\n");
	printf("Stars:\n")l
	printf("\t%s\n",root->stars);
	printf("Address:\n");
	printf("\t%s\n\n", root->address);	
}

void print_tree(BusinessNode * tree) //pre-order traversal
{
	if(tree == NULL)
	{
		return NULL;
	}
	else
	{
		print_node(tree);
		print_tree(tree->left);
		print_tree(tree->right);
	}
	}
*/
