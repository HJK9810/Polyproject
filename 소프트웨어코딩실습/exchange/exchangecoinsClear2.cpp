#include <stdio.h>
#include <string.h>

void changeCoins(int money) {
	const int counts[5] = {1000, 500, 100, 50, 10};
	
	for(int i = 0; i < 5; i++) {
		int coin = money / counts[i];
		money -= coin * counts[i];
		// 지불되는 종류만 출력 
		if(coin != 0) printf("%d원: %d 개. ", counts[i], coin);
	}
	
	printf("\n\n");
}

void changeExchan(int money, char unit[], int input) {
	const int counts[9] = {5000, 1000, 500, 100, 50, 20, 10, 5, 1};
	
	for(int i = 0; i < 9; i++) {
		if(input != 2 && i < 3) continue; // 엔화만 5000, 1000, 500엔 존재 
		if(input == 5 && i == 3) continue; // 파운드는 100파운드 이상 존재X 
		if(input == 2 && i == 5) continue; // 엔화만 20엔 없음 
		
		int coin = money / counts[i];
		money -= coin * counts[i];
		// 지불되는 종류만 출력 
		if(coin != 0) printf("%d%s: %d 개. ", counts[i], unit, coin);
	}
	
	printf("\n\n");
}

int main() {
	int inputWon = 0;
	int input = 0;
		
	const float RATE[] = {1233.1, 9.87, 1342.79, 193.25, 1605.28};
	const char UNIT[][10] = {"달러", "엔", "유로", "위안", "파운드"};
	
	printf("환전을 원하는 금액을 입력하세요(원화) : ");
	scanf("%d", &inputWon);
	
	do{ // 주어진 경우 이외를 입력할경우 반복 
		printf("환전할 외화를 선택하세요 (1:USD, 2:JPY, 3:EUR, 4:CNY, 5:GBP) : ");
		scanf("%d", &input);
	} while (input < 1 || input > 5);
	
	const float rate = RATE[input - 1]; // 해당 환율 입력 
	
	float output = inputWon / rate; // 환전 = 바꾸는 원화 / 환율
	int change = (int) (output * 100) % 100 * rate / 100; // 거스름돈
	
	printf("기준 환율 : %.2f\n\n", rate); // 모든 환율이 소수점 둘째짜리까지기에 .2f 사용 
	printf("환전결과\n");
	printf("%d 원 -> %d %s\n", inputWon, (int) output, UNIT[input - 1]); // 환전 출력
	char unit[10];
	strcpy(unit, UNIT[input - 1]); // 단위를 전달하기 위한 재정의 
	
	changeExchan((int) output, unit, input); // 외화 지불 종류 
	
	printf("거스름돈 : %d 원\n", change / 10 * 10); // 거스름돈 출력 - 1원단위 버림 
	printf("1원단위시 거스름돈 : %d 원\n", change); // 거스름돈 출력 - 1원단위까지 출력 
	changeCoins(change); // 거스름돈 지불 종류 
	
	return 0;
}
