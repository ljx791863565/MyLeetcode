#include <stdio.h>

int main()
{
	int ch;
	int lasic = 'a'; //记录前一个字符的值
	while ((ch = getchar()) != EOF){
		if (ch != ' '){
			putchar(ch);
		}else if (lasic != ' '){
			putchar(ch);
		}
		lasic = ch;
	}
	return 0;
}
