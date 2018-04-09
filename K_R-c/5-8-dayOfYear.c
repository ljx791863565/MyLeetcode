#include <stdio.h>

//用一个二维数组表示闰年和平年每个月的天数
static int daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};


//判断某一天是该年的第几天
int dayToYear(int year, int month, int day)
{
	int i, leap;
	leap = year % 4 == 0 && year % 100 != 0 && year % 400 == 0;
	if (month > 12 || month < 0){
		printf("month error\n");
		return -1;
	}
	if (leap == 0 && month == 2 && day == 29){
		printf("% is not a leap\n",year);
		return -1;
	}
	if (day > daytab[leap][month]){
		printf("day is error\n");
		return -1;
	}
	for (i=1; i < month; ++i){
		day += daytab[leap][i];
	}
	return day;
}

//判断该年的某一天是几月几号
void monthDay(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	leap = year % 4 == 0 && year % 100 != 0 && year % 400 == 0;
	if (yearday <0 || (leap == 0 && yearday > 365) || (leap == 1 && yearday > 366)){
		printf("yearday is error\n");
		return;
	}
	for (i = 1; yearday > daytab[leap][i]; ++i){
		yearday -= daytab[leap][i];
	}
	*pmonth = i;
	*pday = yearday;
}
int main()
{
	int num = dayToYear(2018, 3, 1);
	printf("num = %d\n",num);
	
	int month ,day;
	monthDay(2018, 60, &month, &day);
	printf("2018 60days is %d month %d day\n", month, day);
	return 0;
}
