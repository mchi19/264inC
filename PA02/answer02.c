#include <stdlib.h>
#include <stdio.h>
#include "answer02.h"

size_t my_strlen(const char * str)
{
	int i = 0;
	int len = 0;
	while(str[i] != '\0')
	{	
		if(str[i] != '\0')
		{
			len++;
		}
		i++;
	}
	return len;
}

int my_countchar(const char * str, char ch)
{
	int i = 0;
	int count = 0; //count occurances of charater 'ch' in the string
	while(str[i] != '\0')
	{
		if(str[i] == ch)
		{
			count++;
		}
		i++;
	}
	return count;
}

char * my_strchr(const char * str, int ch)
{
	int i = 0;
	int x = 0; //terminating variable
	int loc = 0;
	size_t len =(int) my_strlen(str); //type casting type size_t into type int
	while(str[i] != '\0')
	{
	  	if(str[i] == (char) ch)
		{
			if(x == 0) //first match of x and ch
			{
				loc = i;
				x = 1;
				return (char * )(str + loc);
			}
		}
		i++;
	}
	if(ch == '\0')
	{
		return (char *)(str + len);	
	}
	else if((loc == 0) & (x == 0))
	{
		return NULL;	
	}
	return (char *)(str + loc);
}

char * my_strrchr(const char * str, int ch)
{
	int i;
	int x = 0; //times ch is found
	int loc = 0; //location at which ch is found at
	size_t len =(int) my_strlen(str);
	while(str[i] != '\0')
	{
		if(str[i] == (char) ch)
		{
			loc = i;
			x++;
		}
		i++;
	}
	if(ch == '\0')
	{
		return (char *)(str + len);
	}
	else if((loc == 0) & (x == 0))
	{
		return NULL;	
	}
	return (char *)(str + loc);
}

char * my_strstr(const char * haystack, const char * needle)
{
	int start; //begining location
	int i;
	int j = 0;
	int x = 0; //terminating condition 
	size_t len1 =(int) my_strlen(haystack);
	size_t len2 =(int) my_strlen(needle);
	if(needle[0] == '\0')
	{
		return (char *) haystack;
	}
	for(i = 0; i < len1; i++)
	{
		if(haystack[i] == needle[j])
		{
			if(j < (len2)-1)
			{
				j++;
			}
			else if(j == (len2 - 1))
			{
				return (char *) (haystack + start);
			}
			if(x == 0)
			{
				start = i;	
			}
			x = 1; //successful comparison
		}
		else //if(haystack[i] != needle[j])
		{
			x = 0;
			start = 0;
			j = 0;
		}
	}
	if(x == 0)
	{
		return NULL;
	}
	return (char *)(haystack + start);
}

char * my_strcpy(char * dest, const char * src)
{
	int i;
	int j = 0;
	size_t len = (int) my_strlen(src);
	for(i = 0; i <= len; i++)
	{
		dest[i] = src[j];
		j++;
	}
	return dest;
}

char * my_strcat(char * dest, const char * src)
{
	int i;
	int j = 0;
	size_t len = (int) my_strlen(src);
	size_t len_orig = (int) my_strlen(dest);
	for(i = len_orig; i <= (len + len_orig); i++)
	{
		dest[i] = src[j];
		j++;
	}
	return dest;
}

int my_isspace(int ch)
{
	int x; //return variable
	if((ch == ' ')||(ch == '\f')||(ch == '\n')||(ch == '\r')||(ch == '\t')||(ch == '\v'))
	{
		x = 1;
	}
	else
	{
		x = 0;
	}
	return x;
}

int my_atoi(const char * str)
{
	int res = 0; //resulting variable
	int i = 0;
	int x;
	int neg = 0; //negative indicator
	size_t len = (int) my_strlen(str);
	while(i < len)
	{
		x = my_isspace(str[i]);
		if(x == 1)
		{
			i++;
		}
		else if(x == 0)
		{
			if(((str[i] > '@') && (str[i] < '[')) || ((str[i] > '`') && (str[i] < '{')))  
			{
					return res;
			}
			else if(str[i] == '+')
			{
				if(!((str[i+1] >='0') && (str[i+1] <= '9'))) 
				{
					return res;
				}
				neg = 0;
			}	
			else if(str[i] == '-')
			{
				if(!((str[i+1] >= '0') && (str[i+1] <= '9')))
				{
					return res;
				}
				neg = 1;
			}
			else if((str[i] >= '0') && (str[i] <= '9')) //if str[i] is a number
			{
				res = res*10 + (str[i] - '0');
				if(!((str[i+1] >= '0') && (str[i+1] <= '9'))) //if str[i+1] is not a number
				{
					if(neg == 1)
					{
						res = 0 - res;
					}
					return res;
				}
			}
		i++;
		}
	}
	if(neg == 1)
	{
		res = 0 - res;
	}
	return res;
}
