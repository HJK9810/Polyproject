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
	
	printf("환전을 원하는 금액을 입력하세요(원화) : ");
	scanf("%d", &inputWon);
	printf("\n");
	printf("환전할 외화를 선택하세요 (1:USD, 2:JPY, 3:EUR, 4:CNY, 5:GBP) : ");
	scanf("%d", &input);
	printf("\n");
	
	if(input == 1) { // USD
		float outputUSD = inputWon / RATE_USD; // 환전 = 바꾸는 원화 / 환율
		int finalOutputUSD = outputUSD; 
		change = (int) (outputUSD * 100) % 100 * RATE_USD / 100; // 거스름돈
		
		printf("USD 환전\n");
		printf("%d 원 -> %d 달러\n", inputWon, finalOutputUSD); // 환전 출력 
	} else if(input == 2) { // JPY
		float outputJPY = inputWon / RATE_JPY; // 환전 = 바꾸는 원화 / 환율
		int finalOutputJPY = outputJPY; 
		change = (int) (outputJPY * 100) % 100 * RATE_JPY; // 거스름돈
			
		printf("JPY 환전\n");
		printf("%d 원 -> %d 엔\n", inputWon, finalOutputJPY); // 환전 출력 
	} else if(input == 3) { // EUR
		float outputEUR = inputWon / RATE_EUR; // 환전 = 바꾸는 원화 / 환율
		int finalOutputEUR = outputEUR; 
		change = (int) (outputEUR * 100) % 100 * RATE_EUR / 100; // 거스름돈
			
		printf("EUR 환전\n");
		printf("%d 원 -> %d 유로\n", inputWon, finalOutputEUR); // 환전 출력 
	} else if (input == 4) { // CNY
		float outputCNY = inputWon / RATE_CNY; // 환전 = 바꾸는 원화 / 환율
		int finalOutputCNY = outputCNY; 
		change = (int) (outputCNY * 100) % 100 * RATE_CNY / 100; // 거스름돈
			
		printf("CNY 환전\n");
		printf("%d 원 -> %d 위안\n", inputWon, finalOutputCNY); // 환전 출력 
	} else if(input == 5) { // GBP
		float outputGBP = inputWon / RATE_GBP; // 환전 = 바꾸는 원화 / 환율
		int finalOutputGBP = outputGBP; 
		change = (int) (outputGBP * 100) % 100 * RATE_GBP / 100; // 거스름돈
		
		printf("GBP 환전\n");
		printf("%d 원 -> %d 파운드\n", inputWon, finalOutputGBP); // 환전 출력 
	}
	
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
	
	printf("거스름돈 : %d 원\n\n", change / 10 * 10); // 거스름돈 출력
	printf("1000원 %d개. 500원 %d개. 100원 %d개. 50원 %d개. 10원 %d개.", return1000, return500, return100, return50, return10);
	
	return 0;
}
