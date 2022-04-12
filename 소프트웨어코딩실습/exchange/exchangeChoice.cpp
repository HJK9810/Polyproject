#include <stdio.h>

int calExchange(float rate, int inputWon) {
	float output = inputWon / rate; // 환전 = 바꾸는 원화 / 환율
	return (int) (output * 100) % 100 * rate / 100; // 거스름돈
}

void changCoins(int money) {
	int return1000 = money / 1000;
	money -= return1000 * 1000;
	int return500 = money / 500;
	money -= return500 * 500;
	int return100 = money / 100;
	money -= return100 * 100;
	int return50 = money / 50;
	money -= return50 * 50;
	int return10 = money / 10;
	
	printf("1000원 %d개. 500원 %d개. 100원 %d개. 50원 %d개. 10원 %d개.", return1000, return500, return100, return50, return10);
}

int main() {
	const float RATE_USD = 1233.1;
	const float RATE_JPY = 9.87;
	const float RATE_EUR = 1342.79;
	const float RATE_CNY = 193.25;
	const float RATE_GBP = 1605.28;
	int inputWon = 0; // 원화 
	int input = 0; // 원하는 외화 선택용
	float rate = 0.0;
	
	printf("환전을 원하는 금액을 입력하세요(원화) : ");
	scanf("%d", &inputWon);
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
	
	int change = calExchange(rate, inputWon);
	
	// 출력 
	printf("환전결과\n");
	printf("%d 원 -> %d ", inputWon, (int) (inputWon / rate)); // 환전 출력
	
	switch(input) {
		case 1: // USD
			printf("달러\n");
			break;
		case 2: // JPY
			printf("엔\n");
			break;
		case 3: // EUR
			printf("유로\n");
			break;
		case 4: // CNY
			printf("위안\n");
			break;
		case 5: // GBP
			printf("파운드\n");
			break;
		default:
			break;
	}

	printf("거스름돈 : %d 원\n\n", change / 10 * 10); // 거스름돈 출력
	changCoins(change);
	
	return 0;
}
