#include <stdio.h>

void print(int day, int date) {
	int line = 0;
	
	for(int idx = 1; idx < date + 1; idx++) {
		if(idx == 1 && line < day) {
			printf("\t");
			idx -= 1; // 빈 값은 빈 상태로 만들어야 함 
		} else {
			printf("%4d%4s", idx, " ");
		} 
		line++;
		
		if(line == 7) {
			printf("\n");
			line = 0;
		}
	}
	
	printf("\n\n");
}

int main() {
	int year = 1900;
	int month = 1;	
	
	while(true) {
		printf("  년도 입력 : ");
		scanf("%d", &year);
		if(year == 0) break;
		
		printf("  월 입력 : ");
		scanf("%d", &month);
		printf("\n\n");	
		
		int count = year - 1900;
		int leap = 0; // 윤년수 
		int common = 0; // 평년수 
		
		for(int idx = 0; idx < count; idx++) {
			int checkY = 1900 + idx;
			
			// 윤년의 조건 : 4의 배수이자 100의 배수가 아닐때 or 400의 배수일때 
			if (checkY % 4 == 0 && checkY % 100 != 0) leap++;
			else if(checkY % 400 == 0) leap++;
			else common++;
		}
		
		int date = 30;
		int dateSum = 0;
		for(int idx = 1; idx < month + 1; idx++) {
			switch(idx) { // 해당 달 마지막날 구하기 
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					date = 31;
					break;
				case 2:
					if (year % 4 == 0 && year % 100 != 0) date = 29;
					else if(year % 400 == 0) date = 29;
					else date = 28;
					break;
				default:
					date = 30;
					break;
			}
			dateSum += date;		
		}
		// 앞의 괄호 == 년도 첫요일 => 1900년 1월 == 월요일 == 1
		// 뒤의 괄호 == 해당 달 첫 요일 
		int day =  ((leap * 2 + common + 1) + (dateSum - date)) % 7;

		printf("===================== %d년 %d월 =======================\n", year, month);
		printf("%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s\n", "일", " ", "월", " ", "화", " ", "수", " ", "목", " ", "금", " ", "토");
		print(day, date);
	}

	
	
	
	
	
	return 0;
}
