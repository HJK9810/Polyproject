#include <stdio.h>

int calcul(int year, int month) {
	int count = year - 1900; // 1900년대 이후만 가능한 계산 
	int yearSum = 0; 
		
	for(int idx = 0; idx < count; idx++) { 
		int checkY = 1900 + idx; // 윤년을 알아보기 위한 세팅 
			
		// 윤년의 조건 : 4의 배수이자 100의 배수가 아닐때 or 400의 배수일때
		// 윤년 = 1년 366일, 평년 = 1년 365일 
		if (checkY % 4 == 0 && checkY % 100 != 0) yearSum += 366;
		else if(checkY % 400 == 0) yearSum += 366;
		else yearSum += 365;
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
		// 입력한 월은 몇일이 지났는지 더할필요 없음 
		if(idx != month) dateSum += date;		
	}
		
	// yearsum = 1900년을 기준으로 입력 년도까지 촣 몇일이 지났는지 계산 
	// dateSum = 1월을 기준으로 입력 달 까지 총 몇일이 지났는지 계산 
	int day =  (yearSum + dateSum + 1) % 7; // 요일 계산 = 1주일은 7일 => 0 = 일, 1 = 월.... 
	
	return date * 10 + day;
}

void printUI(int year, int month, int days) { 
	int today = 1; // for 날짜
	int date = days / 10; // 출력 - day : 요일, date : 마지막날짜 
	int day = days % 10;
	
	printf("===================== %d년 %d월 =======================\n", year, month);
	// UI - 앞의 %4s는 요일, 뒤의 %4s는 줄맞춤을 위한 공백 => 토요일은 공백대신, 줄바꿈을 입력 
	printf("%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s\n", "일", " ", "월", " ", "화", " ", "수", " ", "목", " ", "금", " ", "토");
	for(int idx = 0; idx < 5; idx++) { // 한달 == 5주 출력 
		for(int jdx = 0; jdx < 7; jdx++) { // 1주일 출력 
			if(idx == 0 && jdx < day) printf("\t");
			else { // \t == %8s == %8d 
				printf("%4d%4s", today, " ");
				today++; // 날짜 추가 
			}
			
			if(today > date) { // 지정 날자를 모두 출력했을때 
				idx++; // 만약, 해당 일이 넷째주에 끝났을경우 -> idx를 5로 만들어 for문 탈출 
				break; // 내부 for문 종료 
			}
		}
		printf("\n"); // 해당 주가 끝났기에 줄바꿈 
	}
	
	printf("\n\n"); // 달력출력 완료후, 다음 새 달력을 위한 빈칸띄우기 2줄 
}

int main() {
	int year = 1900; // 컴퓨터 기본 년도 
	int month = 1;	// 컴퓨터 기본 월 
	
	while(true) { // 무한루프 
		printf("  년도 입력(1900년대 이후만 가능합니다. 0은 종료입니다.) : ");
		scanf("%d", &year);
		
		if(year == 0) break; // 년도가 0일경우, 무한루프 종료 
		else if(year < 1900) continue; // 범위 이내일경우, 재입력 
		
		printf("  월 입력(1 ~ 12사이만 입력 가능합니다.) : ");
		scanf("%d", &month);
		
		if (month < 1 || month > 13) continue; // 범위 이내일경우, 재입력 
		
		printf("\n\n");	
		
		int days =  calcul(year, month); // days = 마지막날 * 10 + 요일(0~6) 
		printUI(year, month, days); // 출력을 위한 함수 
	}

	return 0;
}
