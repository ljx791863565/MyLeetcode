/*
   实现 strcmp(const char *str1, const char *str2);
		strncmp(const char * str1, const char *str2, const size_t n);
   */

#include <stdio.h>
#include <unistd.h>
#include <assert.h>

int mystrcmp(const char *str1, const char *str2)
{
	assert(str1 && str2);
	while (*str1 != '\0' && *str2 != '\0'){
		++str1;
		++str2;
	}
	return *str1 - *str2;
}
int mystrncmp(const char*str1, const char* str2, const size_t n)
{
	assert(str1 && str2);
	int i;
	for(i=0; i<n; ++i){
		if (str1[i] == str2[i]){
			continue;
		}else if (str1[i] > str2[i]){
			return 1;
		}else{
			return -1;
		}
		return 0;
	}
}
int main()
{
	char s1[20] = "hellA";
	char s2[20] = "world";
	char s3[20] = "hell";
	int num = mystrcmp(s1, s3);
	printf("num = %d\n", num);
		
	return 0;
}
