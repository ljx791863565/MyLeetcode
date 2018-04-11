#include <stdio.h>

int main()
{
	int year, month, day, DaythOfCount;

	while (scanf("%d %d", &year, &DaythOfCount) != EOF){
		LocateOfYear(year, DaythOfCount, &month, &day);
		printf("%d year %d th is %d month %d day\n", year, DaythOfCount, month, day);
	}

	int year1, month1, day1, year2, month2, day2;
	printf("输入第一个日期\n");
	scanf("%d %d %d", &year1, &month1, &day1);
	printf("输入第二个日期， 默认在第一个日期之后\n");
	scanf("%d %d %d", &year2, &month2, &day2);

	int num = IntervalOfTwoDay(year1, month1, day1, year2, month2, day2);
	printf("%d year %d month %d day interval %d year %d month %d day is 
		%d day\n",year1, month1, day1, year2, month2, day2, num);


	while (scanf("%d %d %d", &year, &month, &day) != EOF){
		int week = WeekDayOfYear(year, month, day);		
		WeekdayShow(week);
	}

	while (scanf("%d", &year) != EOF){
		YearShow(year);
	}
	return 0;
}
