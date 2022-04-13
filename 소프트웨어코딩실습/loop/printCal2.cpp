#include <stdio.h>

void print(int day, int date) { // 출력 - day : 요일, date : 마지막날짜 
	int today = 1; // for 날짜

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
		int dates[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // idx = 각 달 => 윤년기준, 1년 모든달 날짜수 
		printf("  년도 입력(1900년대 이후만 가능합니다. 0은 종료입니다.) : ");
		scanf("%d", &year);
		
		if(year == 0) break; // 년도가 0일경우, 무한루프 종료 
		else if(year < 1900) continue; // 범위 이내일경우, 재입력 
		
		printf("  월 입력(1 ~ 12사이만 입력 가능합니다.) : ");
		scanf("%d", &month);
		
		if (month < 1 || month > 13) continue; // 범위 이내일경우, 재입력 
		
		printf("\n\n");	
		
		int count = year - 1900; // 1900년대 이후만 가능한 계산 
		int yearSum = 0; // 입력 전년도까지 지난 총 날짜수 합 
		
		for(int idx = 0; idx < count; idx++) { 
			int checkY = 1900 + idx; // 윤년을 알아보기 위한 세팅 
			
			// 윤년의 조건 : 4의 배수이자 100의 배수가 아닐때 or 400의 배수일때
			// 윤년 = 1년 366일, 평년 = 1년 365일 
			if (checkY % 4 == 0 && checkY % 100 != 0) yearSum += 366;
			else if(checkY % 400 == 0) yearSum += 366;
			else {
				yearSum += 365;
				dates[2] = 28; // 배열 초기화가 윤년기준이기에 
			}
		}
		
		int dateSum = 0;
		for(int idx = 1; idx < month; idx++) {
			dateSum += dates[idx];
		}
		
		// yearsum = 1900년을 기준으로 입력 년도까지 촣 몇일이 지났는지 계산 
		// dateSum = 1월을 기준으로 입력 달 까지 총 몇일이 지났는지 계산 
		int day =  (yearSum + dateSum + 1) % 7; // 요일 계산 = 1주일은 7일 => 0 = 일, 1 = 월.... 

		printf("===================== %d년 %d월 =======================\n", year, month);
		// UI - 앞의 %4s는 요일, 뒤의 %4s는 줄맞춤을 위한 공백 => 토요일은 공백대신, 줄바꿈을 입력 
		printf("%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s\n", "일", " ", "월", " ", "화", " ", "수", " ", "목", " ", "금", " ", "토");
		print(day, dates[month]); // 출력을 위한 함수 - 요일, 해당달 마지막날 
	}

	return 0;
}
