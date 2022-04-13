#include <stdio.h>

int main() {
	int year;
	int day = 28; // 2월 날짜 : 윤년 = 29, 평년 = 28 
	
	printf("원하는 연도를 입력하세요 : ");
	scanf("%d", &year);
	
	// 윤년의 조건 : 4의 배수이자 100의 배수가 아닐때 or 400의 배수일때 
	if (year % 4 == 0 && year % 100 != 0) day = 29;
	else if(year % 400 == 0) day = 29;
	
	// 해당 년도 출력 
	printf("%d년은 다음과 같습니다.\n", year);
	
	printf("1월 : 31일\n");
	printf("2월 : %d일 * 윤년 29일 , 평년 28일\n", day);
	printf("3월 : 31일\n");
	printf("4월 : 30일\n");
	printf("5월 : 31일\n");
	printf("6월 : 30일\n");
	printf("7월 : 31일\n");
	printf("8월 : 31일\n");
	printf("9월 : 30일\n");
	printf("10월 : 31일\n");
	printf("11월 : 30일\n");
	printf("12월 : 31일\n");

	return 0;
} 
