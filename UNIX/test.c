#include <stdio.h>
#include <string.h>
#include <pwd.h>

int main()
{
	const char str[20] = "root";
	struct passwd *pw = getpwnam(str);

	printf("name = %s, pwd = %s\n", pw->pw_name, pw->pw_passwd);

	return 0;
}
