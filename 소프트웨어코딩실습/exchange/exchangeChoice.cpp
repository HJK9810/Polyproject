#include <stdio.h>

int main() {
	const float RATE_USD = 1233.1;
	const float RATE_JPY = 9.87;
	const float RATE_EUR = 1342.79;
	const float RATE_CNY = 193.25;
	const float RATE_GBP = 1605.28;
	int inputWon = 0; // 원화 
	int change  = 0; // 거스름돈 
	int input = 0; // 원하는 외화 선택용 
	int return1000;
	int return500;
	int return100;
	int return50;
	int return10;
	int newChange = 0; // 동전계산을 위한 거스름돈
	float rate = 0.0;
	const char UNIT[][10] = {"달러", "엔", "유로", "위안", "파운드"};
	
	printf("환전을 원하는 금액을 입력하세요(원화) : ");
	scanf("%d", &inputWon);
	printf("\n");
	printf("환전할 외화를 선택하세요 (1:USD, 2:JPY, 3:EUR, 4:CNY, 5:GBP) : ");
	scanf("%d", &input);
	printf("\n");
	
	switch(input) {
		case 1: // USD
			rate = RATE_USD;
			break;
		case 2: // JPY
			rate = RATE_JPY;
			break;
		case 3: // EUR
			rate = RATE_EUR;
			break;
		case 4: // CNY
			rate = RATE_CNY; 
			break;
		case 5: // GBP
			rate = RATE_GBP;
			break;
		default:
			break;
	}
	
	float output = inputWon / rate; // 환전 = 바꾸는 원화 / 환율
	int finalOutput = output; 
	change = (int) (output * 100) % 100 * rate / 100; // 거스름돈
	
	newChange = change;
	return1000 = newChange / 1000;
	newChange -= return1000 * 1000;
	return500 = newChange / 500;
	newChange -= return500 * 500;
	return100 = newChange / 100;
	newChange -= return100 * 100;
	return50 = newChange / 50;
	newChange -= return50 * 50;
	return10 = newChange / 10;
	
	printf("환전결과\n");
	printf("%d 원 -> %d %s\n", inputWon, finalOutput, UNIT[input - 1]); // 환전 출력 
	printf("거스름돈 : %d 원\n\n", change / 10 * 10); // 거스름돈 출력
	printf("1000원 %d개. 500원 %d개. 100원 %d개. 50원 %d개. 10원 %d개.", return1000, return500, return100, return50, return10);
	
	return 0;
}
