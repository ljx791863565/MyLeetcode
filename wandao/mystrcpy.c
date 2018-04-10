/*
   实现
	char * strcpy(char *str1, const char *str2);
	char * strcpy(char *str1, const char *str2, size_t n);
   */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

char * mystrcpy(char *str1, const char *str2)
{
	assert(str1 && str2);
	while ((*str1++ = *str2++ )!= '\0'){
	}
	return str1;
}
char * mystrncpy(char *str1, const char *str2, const size_t n)
{
	int i;
	for (i=0; i<n; ++i){
		str1[i] = str2[i];
	}
}
int main()
{
	char s[20];
	char s2[40] = "helloweirlsdddddddddddd";
	mystrncpy(s, s2, 12);
	printf("%s\n", s);
}
