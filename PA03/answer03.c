#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "answer03.h"

char * strcat_ex(char ** dest, int * n, const char * src)
{
	char * buffer;
	if(*dest == NULL)
	{
		*n = 1 + 2* strlen(src);
		*dest = malloc(*n * sizeof(char)); //buffer;
		strcat(*dest, src);
		return *dest;
	}
	if((strlen(*dest) + strlen(src)+1) > *n)
	{
		buffer = malloc((1 + 2*(strlen(src) + strlen(*dest)))* sizeof(char));
		*n = 1 + 2*(strlen(src) + strlen(*dest));
		strcpy(buffer, *dest);
		free(*dest);
		*dest = buffer;
		strcat(*dest, src);
	}
	else
	{
		strcat(*dest, src);
	}
	return *dest;
}

char ** explode(const char * str, const char * delims, int * arrLen)
{
	int i = 0;
	int j;
	int k;
	int l;
	int len_s = strlen(str); //length of string
	int d_count = 0; //delim counter
	char ** tsArr;
	int s_loc[len_s]; //location/indicator of delim in str 0 = no, 1 = yes
	int previ = 0; // previous last index of word
	int w_len = 0; //length or word being copied
	for(l = 0; l < len_s; l++)
	{
		s_loc[l] = -1;
	}
	for(j = 0; j < len_s; j++)
	{
		if(strchr(delims, str[j]) == NULL) //not a delim
		{
			s_loc[j] = 0;
		}
		else //if there are 
		{
			d_count++;
			s_loc[j] = 1; //indicates location in str
		}
	} 
	tsArr = malloc((d_count+1)*sizeof(char*));
	*arrLen = d_count + 1;
		for(k = 0; k <= len_s; k++)
		{
			if((s_loc[k] == 1) || (s_loc[k] == '\0'))
			{
				tsArr[i] = malloc(sizeof(char)* (w_len + 1));
				memcpy(tsArr[i], str+previ, w_len);
				tsArr[i][w_len] = '\0';
				w_len = 0;
				previ = k;
				i++;
			}
			else if(s_loc[k] == 0)
			{
				w_len++;
			}
		}
	return tsArr;
}

char * implode(char ** strArr, int len, const char * glue)
{
	int i;
	int j;
	char * temp_str; //temp single string to hold all elements
	int length = 0; //length of all *strArrs added together
	int tot_len = 0; //total length of all *strArrs and glue*len added in
	for(i = 0; i < len; i++) //len is the number of *strArr there are
	{
		length += strlen(strArr[i]);
	}
	tot_len = length + (len)*(strlen(glue))+1;
	temp_str = malloc((sizeof(char) * tot_len));
	for(j = 0; j < len; j++)
	{
		if(j == (len - 1))
		{
			strcpy(temp_str, strArr[j]);
		}
		else
		{
			strcat(temp_str, strArr[j]);
			strcat(temp_str, glue);
		}
	}	
	return temp_str;
}

