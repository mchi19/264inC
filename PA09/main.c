#include "answer09.h"



int main(int argc, char ** argv)
{

	Node * head = NULL;
	head = List_insert(head,90);
	head = List_insert(head,4);
	head = List_insert(head,50);
	head = List_insert(head,15);
	head = List_insert(head,62);
	head = List_insert(head,24);
	List_print(head); // Should print [0]:90 [1]:4 [2]:50 [3]:15 [4]:62 [5]:24 

	//Uncomment the below code as you test your functions

	List_swap(head,1,3);
	List_print(head); //Should print [0]:90 [1]:15 [2]:50 [3]:4 [4]:62 [5]:24 
	
	printf("%d\n",List_read(head,2)); //Should print 50

	List_write(head,0,89); 
	List_print(head); //Should print [0]:89 [1]:15 [2]:50 [3]:4 [4]:62 [5]:24 
	
	List_qsort(head, List_length(head));
	List_print(head); //Should print [0]:4 [1]:15 [2]:24 [3]:50 [4]:62 [5]:89

	int ret1 = List_writeToTextFile(head, "textOutput"); //Should be the same as textOutput_test
	if(ret1 != EXIT_SUCCESS)
	{
		printf("Write to text file not successful");
	}

	int ret = List_writeToBinaryFile(head, "binaryOutput"); //Should be the same as binaryOutput_test
	if(ret != EXIT_SUCCESS)
	{
		printf("Write to binary file not successful");
	}

	List_destroy(head);

	head = List_readFromTextFile("textInput_test"); 
	List_print(head); //Should print [0]:8 [1]:6 [2]:7 [3]:5 [4]:3 [5]:0 [6]:9 

	List_destroy(head);

	head = List_readFromBinaryFile("binaryOutput_test");
	if(head ==NULL)
	{
		printf("Unsuccessful linked list reading");
		return EXIT_FAILURE;
	}
	List_print(head); //Should print [0]:4 [1]:15 [2]:24 [3]:50 [4]:62 [5]:89

	List_destroy(head);
	
	return EXIT_SUCCESS;

}

