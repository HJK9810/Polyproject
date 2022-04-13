#include <stdio.h>

int main() {
	int year = 0;
	
	printf("원하는 년도를 입력하세요 : ");
	scanf("%d", &year);
	// 윤년의 조건 : 4의 배수이자 100의 배수가 아닐때 or 400의 배수일때 
	if (year % 4 == 0 && year % 100 != 0) {
		printf("윤년 입니다.\n");
	} else if(year % 400 == 0) {
		printf("윤년 입니다. \n");
	} else {
		printf("윤년이 아닙니다.\n");
	}
	
	return 0;
}
