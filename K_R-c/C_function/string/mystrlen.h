#include <stdio.h>

/*find length of s[]*/	
size_t myStrlen(const char *s)
{
	const char *sc;
	for (sc = s; *sc != '\0'; ++sc){
		;
	}
	return (sc - s);
}
