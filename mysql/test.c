#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, NULL, "root", "123", "stu", 0, NULL, 0);
	mysql_real_query(&mysql, "select * from info", 16);

	MYSQL_RES *res = mysql_store_result(&mysql);
	int num_fields = mysql(res);

	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res))){
		int i;
		for (i=0; i<num_fields; i++){
			char buf[100];
			sprintf(buf, "[%s]", row[i]?row[i]:"NULL");
			printf("%s", buf);
		}
		printf("\n");
	}

	mysql_free_result(res);
	mysql_close(&mysql);

	exit(0);
}
