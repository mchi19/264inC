#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer09.h"

int main()
{
	char * str1 = stdup("01");
	char * str2 = stdup("02");
	char * str3 = stdup("03");
	BusinessNode * node1 = create_node(str1, str2, str3);

	destroy_tree(node1);

	return 0;
}
