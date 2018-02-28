#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{
	int sum = 0;
	int i;	
	for(i = 0; i < len; i++)
	{
		sum += array[i];
	}
	return sum;
}

int arrayCountNegative(int * array, int len)
{
	int negcount = 0;
	int i;
	for(i = 0; i< len; i++)
	{
		if(array[i] < 0)
		{
			negcount++;
		}
	}
	return negcount; 
}

int arrayIsIncreasing(int * array, int len)
{
	int i;
	int x; //previous element in array
	int isIncr = 0;
	if(len == 0)
	{
		isIncr = 1;
		return isIncr;
	}
	for(i = 0; i < len; i++)
	{
		if(i == 0)
		{
			x = array[i];
		}
		else
		{
			if(x <= array[i])
			{
		        isIncr = 1;
				x = array[i];
			}
			else
			{
		        isIncr = 0;
				x = array[i];
				return isIncr;
			}
		}
	}
	return isIncr;
}

int arrayIndexFind(int needle, const int * haystack, int len)
{
    int a = 0; //terminating variable
	int i;
	int n_index; //needle location index
	for(i = 0; i < len; i++)
	{
		if(haystack[i] == needle)
		{
			n_index = i;
			a = 1;
		}
		if(a == 0)
		{
			n_index = -1;
		}
	}
	return n_index;
}

int arrayFindSmallest(int * array, int len)
{
    int x;
	int i;
	int s_index; //smallest number index
	if(len == 0)
	{
		return 0;
	}
	for(i = 0; i< len; i++)
	{
		if(i == 0)
		{
		    x = array[i];
			s_index = i;
		}
		else
		{
			if(x > array[i])
		    {
		    	x = array[i];
		    	s_index = i;
		    }
		  	else if(x == array[i])
		    {
		    	x = array[i];
		    }
		}
    }
        return s_index;
}
