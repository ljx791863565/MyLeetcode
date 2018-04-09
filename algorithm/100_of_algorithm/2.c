/*
   求奖金
   */


#include <stdio.h>

int main()
{
	int bonus;
	int profit;
	scanf("%d", &profit);
	if (profit <= 100000){
		bonus = profit * 0.1;
	}else if (profit <= 200000){
		bonus = 100000 * 0.1 + (profit - 100000) * 0.075;
	}else if (profit <= 40){
		bonus = 100000 * 0.1 + 100000 * 0.075 + (profit - 200000) * 0.05;
	}else if (profit <= 60){
		bonus = 100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 + (profit - 40) * 0.03;
	}else if (profit <= 1000000){
		bonus = 100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 + 200000 * 0.03 + (profit - 600000) * 0.015;
	}else{
		bonus = 100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 + 200000 * 0.03 + 400000 * 0.015 + (profit - 1000000) * 0.01;
	}

	printf("bonus = %d\n", bonus);
}
