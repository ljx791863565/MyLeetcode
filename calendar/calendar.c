#include <stdio.h>

#define PERIOD_OF_FORE_YEAR (365 * 4 +1)
static int DayOfMonth[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

static int CountOfYear[2] = {
	365,366
};


//判断日期是否合法
int IsRightDay(int year, int month, int day)
{
	int flag = IsLeapYear(year);

	if (month <= 0  || month > 12){
		printf("月份输入有误\n");
		return -1;
	}

	if (day > DayOfMonth[flag][month] || day < 0){
		printf("日期输入有误\n");
		return -1;
	}
	
	if (year > 10000 || year < 1900){
		printf("年份输入有误\n");
		return -1;
	}
}

//判断是否闰年 返回1表示闰年
int IsLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
		return 1;
	}else{
		return 0;
	}
}

//输入年月日返回该天是当年第几天
int DaythOfYear(int year, int month, int day)
{

	int i;
	int countDay = 0;
	int flag = IsLeapYear(year);
	for (i=1; i<month; ++i){
		countDay += DayOfMonth[flag][i];
	}
	countDay += day;
	
	return countDay;

}

void MonthHeadPrint(int year, int month)
{
	printf("%d 年 %d 月\n", year, month);
	printf("Mon Tue Wed Thu Fri Sat Sun\n");
}


//打印某一个月的日历
void MonthShow(int year, int month)
{
	MonthHeadPrint(year, month);

	//求出该月1号是星期几 0表示周一
	int week = WeekDayOfYear(year, month, 1);
//	printf("week = %d\n",week);
	int line = 0, row = 0, i, j;
	int monthDay = DayOfMonth[IsLeapYear(year)][month];
	for (i=1; i<=monthDay; ++i){
		//当row是0时表示第一行没有打印，需先打印空格
		if (row == 0){
			for (j=0; j<week*4; ++j){
				printf(" ");
			}
			row = 1;
		}
		printf("%3d ", i);
		line++;
		if ((line+week) == 7){
			printf("\n");//一行打印完，需换行
			line = 0;
			week = 0;//不需要打印开头空格，需清零
		}
	}
	printf("\n");
	
}

//打印某年日历
void YearShow(int year)
{
	printf("%d年\n",year);
	int i;
	for (i=1; i<=12; ++i){
		MonthShow(year, i);	
	}
}

//输入一个年份判断是第几世纪
int GetCentunry(int year)
{
	return (year / 100) + 1;
}

//输入一个日期判断这一天是星期几
//基姆拉尔森公式
// 另外一个是蔡勒(Zeller)公式
// w = (y + [y/4] + [c/4] - 2*c +[26*(m+1)/10] + d - 1) % 7
// y是年份后两位  c = centunry-1 d = day
// m >= 3 && m <= 14 即每年1月当成上一年13月 2月当成上一年14月
// 余数0周日，其余余数即周几
int WeekDayOfYear(int year, int month, int day)
{

	if (month == 1){
		month = 13;
	}
	if (month == 2){
		month = 14;
	}

	int week = (day + 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400) % 7;
	return week;
}

void WeekdayShow(int week)
{
	switch (week){
		case 0:
			printf("星期一\n");
			break;
		case 1:
			printf("星期二\n");
			break;
		case 2:
			printf("星期三\n");
			break;
		case 3:
			printf("星期四\n");
			break;
		case 4:
			printf("星期五\n");
			break;
		case 5:
			printf("星期六\n");
			break;
		case 6:
			printf("星期日\n");
			break;
	}

}
//输入年份和一个天数判断这一天是该年几月几日
void LocateOfYear(int year, int count, int *month, int *day)
{
	int i = 1;
	int flag = IsLeapYear(year);
	if (flag){
		if (count > 366 || count < 0){
			printf("该天不在这一年内\n");
			return;
		}
	}else{
		if (count > 365 || count < 0){
			printf("该天不在这一年内\n");
			return;
		}
	}
	for (i=1; count > DayOfMonth[flag][i]; ++i){
		count -= DayOfMonth[flag][i];
	}
	*month = i;
	*day = count;
}

//输入两个日期输出这两天中间差几天
//默认先输入的更早的日期
int IntervalOfTwoDay(int year1, int month1, int day1, int year2, int month2, int day2)
{
	if (!IsRightDay(year1, month1, day1) && !IsRightDay(year2, month2, day2)){
		printf("日期不合法\n");
		return -1;
	}

	int intervalDay = 0, dayth1, dayth2;
	int yearth = year2 - year1;//先确定相隔几年
	int tmp = 0;
	int flag = IsLeapYear(year1);
	tmp = abs(yearth / 4);
	intervalDay = PERIOD_OF_FORE_YEAR * tmp;//四年一个周期的天数
	tmp = abs(yearth % 4);
	intervalDay += 356 * (tmp - 1);
	if (yearth > 0){
		dayth1 = CountOfYear[flag] - DaythOfYear(year1, month1, day1);//第一年还剩余的天数
		dayth2 = DaythOfYear(year2, month2, day2);

		return intervalDay + dayth1 + dayth2;
	}else if (yearth < 0){
		dayth1 = CountOfYear[flag] - DaythOfYear(year2, month2, day2);
		printf("dayth1 = %d\n",dayth1);
		dayth2 = DaythOfYear(year1, month1, day1);
		printf("dayth2 = %d\n",dayth2);

		return intervalDay + dayth1 + dayth2;
	}else if (yearth == 0){
		dayth1 = DaythOfYear(year1, month1, day1);
		dayth2 = DaythOfYear(year2, month2, day2);

		return abs(dayth1 - dayth2);

	}


}

