#include <stdio.h>
#include <stdlib.h>

// The line below includes the /definitions/ of the functions that you write
// in this assignment. Including the definitions allows you to use
// the functions in this file.
#include "answer01.h"

void printArray(int * array, int len)
{
    printf("{");
    int ind;
    for(ind = 0; ind < len; ++ind) {
	printf("%d", array[ind]);
	if(ind != len - 1) {
	    printf(", ");
	}
    }
    printf("}");
    // If we don't include a '\n' character, then we need to 
    // include this line to ensure that our output is immediately
    // printed out output.
    fflush(stdout); 
}

void test_arraySum(int * array, int len, int expected)
{
    printArray(array, len);
    int sum = arraySum(array, len);
    printf(". sum = %d, expected = %d.", sum, expected);
    if(sum != expected)
	printf(" FAIL");
    printf("\n");
}

void test_00_arraySum()
{
    printf("Testing arraySum(...)\n");

    // Here we use "static initialization" to create an array
    int array1[] = { -4, -1, 0, 1, 5, 10, 20, 21 };
    int len1 = 8;
    int expected1 = 52;
    test_arraySum(array1, len1, expected1);

    // Our functions must always work... even on empty arrays
    int array2[1];// = {};
    int len2 = 0;
    int expected2 = 0;
    test_arraySum(array2, len2, expected2);

    // You can add more test-cases here
    // ...

    printf("\n"); // Tidy output is easier to use
}

void test_arrayCountNegative(int * array, int len, int expected)
{
    printArray(array, len);
    int count = arrayCountNegative(array,len); 
    printf(". count = %d, expected = %d.", count, expected);
    if(count != expected)
	printf(" FAIL");
    printf("\n");
}

void test_01_arrayCountNegative()
{
    printf("Testing arrayCountNegative(...)\n");

    int array1[] = { 1, 4, -5, 4 };
    int len1 = 4;
    test_arrayCountNegative(array1, len1, 1);

    int array2[] = {};
    int len2 = 0;
    test_arrayCountNegative(array2, len2, 0);

    int array3[] = { 0, 1, 2, 3, 4 };
    int len3 = 5;
    test_arrayCountNegative(array3, len3, 0);

    int array4[] = { -1, -2, -3, -4 };
    int len4 = 4;
    test_arrayCountNegative(array4, len4, 4);

    // You can add more test-cases here
    // ...

    printf("\n");
}

void test_arrayIsIncreasing(int * array, int len, int expected)
{
	printArray(array, len);
	int x = arrayIsIncreasing(array, len);
	printf(". count = %d, expected = %d.", x, expected);
	if(x != expected)
	printf(" FAIL");
	printf("\n");
}


void test_02_arrayIsIncreasing()
{
	printf("Testing arrayIsIncreasing(...)\n");

	int array1[] = {1, 1, 2, 3, 3};
	int len1 = 5;
	int expected1 = 1;
	test_arrayIsIncreasing(array1, len1, expected1);

	int array2[] = {1, 2, 0, 4};
	int len2 = 4;
	int expected2 = 0;
	test_arrayIsIncreasing(array2, len2, expected2);
	
	int array3[] = {};
	int len3 = 0;
	int expected3 = 1;
	test_arrayIsIncreasing(array3, len3, expected3);

	printf("\n");
}

void test_arrayFindSmallest(int * array, int len, int expected)
{
	printArray(array, len);
	int x = arrayFindSmallest(array, len);
	printf(". smallest location = %d, expected = %d.", x, expected);
	if(x != expected)
	{
		printf(" FAIL");
	}
	printf("\n");
}

void test_04_arrayFindSmallest()
{
	printf("Testing arrayFindSmallest(...)\n");

	int array1[] = {3, 4, -5};
	int len1 = 3;
	int expected1 = 2;
	test_arrayFindSmallest(array1, len1, expected1);

	int array2[] = {4, 1, 2, 3, 1, 5};
	int len2 = 6;
	int expected2 = 1;
	test_arrayFindSmallest(array2, len2, expected2);
}

void test_arrayIndexFind(int needle, const int * haystack, int len, int expected)
{
	printArray((int *)haystack, len);
	printf(". needle = %d", needle);
	int x = arrayIndexFind(needle, haystack,  len);
	printf(". index = %d, expected = %d.", x, expected);
	if(x != expected)
	printf(" FAIL");
	printf("\n");
}

void test_03_arrayIndexFind()
{
	printf("Testing arrayIndexFind(...)\n");

	int haystack[] = {1, 4, -5, 5};
	int len = 4;
	int needle1 = 1;
	int expected1 = 0;
	test_arrayIndexFind(needle1, haystack, len, expected1);
	
	int needle2 = 4;
	int expected2 = 1;
	test_arrayIndexFind(needle2, haystack, len, expected2);

	int needle3 = 6;
	int expected3 = -1;
	test_arrayIndexFind(needle3, haystack, len, expected3);

	int haystack4[] = {5, -2, 1, 6, 3, 4};
	int len4 = 6;
	int needle4 = 3;
	int expected4 = 4;
	test_arrayIndexFind(needle4, haystack4, len4, expected4);

	int haystack5[] = {1, 2, 3, 2, 5};
	int len5 = 5;
	int needle5 = 2;
	int expected5 = 3;
	test_arrayIndexFind(needle5, haystack5, len5, expected5);

	printf("\n");
}

int main(int argc, char * * argv)
{
    printf("Welcome to ECE264, we are working on PA01.\n\n");

    // Uncomment to run two example (incomplete) testcases.
    test_00_arraySum();
    test_01_arrayCountNegative();
	test_02_arrayIsIncreasing();
	test_03_arrayIndexFind();
	test_04_arrayFindSmallest();
	
	//If you write any additional test functions, you can call them below

    return EXIT_SUCCESS;
}
