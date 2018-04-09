/*
   输入某年某月，判断这是这一年的第几天
   输入某年及天数，判断这一天日期
*/

static int mon[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};
#include <stdio.h>

//判断闰年
int isLoapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
		return 1;
	}else{
		return 0;
	}
}
//输出是该年第几天
int getCountOfYear(int year, int month, int day)
{
	int count = 0;
	int i;
	int loapyear = isLoapYear(year);
	printf("loapyear = %d\n",loapyear);
	for (i=1; i<month; ++i){
		count += mon[loapyear][i];
	}
	count += day;
	return count;
}

//输出这一天是这一年的日期
void getDaythOfCount(int year, int count, int *month, int *day)
{
	int loap = isLoapYear(year);
	int i =1;
	for (i=1; count > mon[loap][i]; ++i){
		count -= mon[loap][i];
	}
	*month = i;
	*day = count;
}
int main()
{
	int year, month, day;
	/*
	while (scanf("%d %d %d", &year, &month, &day) != EOF){
		int loap = isLoapYear(year);
		if (month < 1 && month > 12){
			printf("month error\n");
			return -1;
		}
		if (day > mon[loap][month]){
			printf("day error\n");
			return -1;
		}
		int countDay = getCountOfYear(year, month, day);
		printf("%d year %d month %d day is the %d th days\n", year, month, day, countDay);
	}
	*/
	
	int count;
	while (scanf("%d %d", &year, &count) != EOF){
		int loap = isLoapYear(year);
		if (loap && count > 366){
			printf("day error\n");
			return -1;
		}
		if (!loap && count > 365){
			printf("day error\n");
			return -1;
		}
		getDaythOfCount(year, count, &month, &day);
		printf("%d year %d th is %d month %d day\n",year, count, month, day);
	}
	
	return 0;
}
