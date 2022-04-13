#include <stdio.h>

void print(int day, int date) {
	int line = 0;
	
	for(int idx = 1; idx < date + 1; idx++) {
		if(idx == 1 && line < day) { // 해당 요일이 첫 요일과 동일하지 않을때 
			printf("\t");
			idx -= 1; // 빈 값은 빈 상태로 만들어야 함 
		} else {
			printf("%4d%4s", idx, " "); // UI를 좋게 출력 - 앞의 빈칸 + 숫자 + 빈칸 4칸 
		} 
		line++; // 요일이 지난상태 
		
		if(line == 7) { // 마지막요일에 도달 
			printf("\n"); // 줄바꿈 
			line = 0; // 초기화 
		}
	}
	
	printf("\n\n"); // 달력출력 완료후, 다음 새 달력을 위한 빈칸띄우기 2줄 
}

int main() {
	int year = 1900; // 컴퓨터 기본 년도 
	int month = 1;	// 컴퓨터 기본 월 
	
	while(true) { // 무한루프 
		do {
			printf("  년도 입력(1900년대 이후만 가능합니다.) : ");
			scanf("%d", &year);
		} while (year < 1900);
		
		if(year == 0) break; // 년도가 0일경우, 무한루프 종료 
		
		do {
			printf("  월 입력(1 ~ 12사이만 입력 가능합니다.) : ");
			scanf("%d", &month);
		} while (month < 1 || month > 13);
		
		printf("\n\n");	
		
		int count = year - 1900; // 1900년대 이후만 가능한 계산 
		int leap = 0; // 윤년수 
		int common = 0; // 평년수 
		
		for(int idx = 0; idx < count; idx++) { 
			int checkY = 1900 + idx; // 윤년을 알아보기 위한 세팅 
			
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
		
		// 윤년은 전년보다 요일이 이틀 차이나지만, 평년은 하루 차이남 
		// 앞의 괄호 == 년도 첫요일 => 1900년 1월 == 월요일 == 1
		// 뒤의 괄호 == 해당 달 첫 요일 
		int day =  ((leap * 2 + common + 1) + (dateSum - date)) % 7;

		printf("===================== %d년 %d월 =======================\n", year, month);
		// UI - 앞의 %4s는 요일, 뒤의 %4s는 줄맞춤을 위한 공백 => 토요일은 공백대신, 줄바꿈을 입력 
		printf("%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s\n", "일", " ", "월", " ", "화", " ", "수", " ", "목", " ", "금", " ", "토");
		print(day, date);
	}

	
	
	
	
	
	return 0;
}
