#include <stdlib.h>
#include <stdio.h>

int bad_strlen(const char * str)
{
int len = 0;
while((*str) != '\0')
{
len++;
str++;
}
return len;
}

int main(int argc, char **argv)
{
char string[10] = {};//'P'};//, 'u', 'r', 'd', 'u', 'e','2','0','1','5'};
int len = bad_strlen(string);
printf("len = %d\n", len);
return EXIT_SUCCESS;
}
