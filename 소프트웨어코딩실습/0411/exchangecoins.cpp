#include <stdio.h>

int main() {
	const float RATE_USD = 1233.1;
	const float RATE_JPY = 9.87;
	const float RATE_EUR = 1342.79;
	const float RATE_CNY = 193.25;
	const float RATE_GBP = 1605.28;
	int inputWon = 0;
	int change  = 0;
	int coins[5] = {0, 0, 0, 0, 0};
	int counts[5] = {1000, 500, 100, 50, 10};
	int newChange = 0;
	
	printf("환전을 원하는 금액을 입력하세요(원화) : ");
	scanf("%d", &inputWon);
	printf("\n");
	
	float outputUSD = inputWon / RATE_USD; // 환전 = 바꾸는 원화 / 환율
	int finalOutputUSD = outputUSD; 
	change = (int) (outputUSD * 100) % 100 * RATE_USD / 100; // 거스름돈
	
	newChange = change / 10; // 최솟값이 10원단위이기에 	
	for(int i = 4; i > 0; i--) {
		if(i % 2 == 0) {
			int num = newChange % 10; // 10원단위의 값 산출 
			if(num < 5) {
				coins[i] = num;
				coins[i - 1] = 0;
			} else {
				coins[i] = num - 5;
				coins[i - 1] = 1;
			}
			newChange /= 10;
		}
	}
	coins[0] = newChange;
	
	printf("USD 환전\n");
	printf("%d 원 -> %d 달러\n", inputWon, finalOutputUSD); // 환전 출력 
	printf("거스름돈 : %d 원\n", change / 10 * 10); // 거스름돈 출력 
	
	for(int i = 0; i < 5; i++) {
		if(coins[i] != 0) printf("%d원: %d 개\n", counts[i], coins[i]);
	}
	printf("\n");
	
	float outputJPY = inputWon / RATE_JPY; // 환전 = 바꾸는 원화 / 환율
	int finalOutputJPY = outputJPY; 
	change = (int) (outputJPY * 100) % 100 * RATE_JPY; // 거스름돈
	
	newChange = change / 10; // 최솟값이 10원단위이기에 	
	for(int i = 4; i > 0; i--) {
		if(i % 2 == 0) {
			int num = newChange % 10; // 10원단위의 값 산출 
			if(num < 5) {
				coins[i] = num;
				coins[i - 1] = 0;
			} else {
				coins[i] = num - 5;
				coins[i - 1] = 1;
			}
			newChange /= 10;
		}
	}
	coins[0] = newChange;
		
	printf("JPY 환전\n");
	printf("%d 원 -> %d 엔\n", inputWon, finalOutputJPY); // 환전 출력 
	printf("거스름돈 : %d 원\n\n", change / 10 * 10); // 거스름돈 출력
		
	for(int i = 0; i < 5; i++) {
		if(coins[i] != 0) printf("%d원: %d 개\n", counts[i], coins[i]);
	}
	printf("\n");
	
	float outputEUR = inputWon / RATE_EUR; // 환전 = 바꾸는 원화 / 환율
	int finalOutputEUR = outputEUR; 
	change = (int) (outputEUR * 100) % 100 * RATE_EUR / 100; // 거스름돈
	
	newChange = change / 10; // 최솟값이 10원단위이기에 	
	for(int i = 4; i > 0; i--) {
		if(i % 2 == 0) {
			int num = newChange % 10; // 10원단위의 값 산출 
			if(num < 5) {
				coins[i] = num;
				coins[i - 1] = 0;
			} else {
				coins[i] = num - 5;
				coins[i - 1] = 1;
			}
			newChange /= 10;
		}
	}
	coins[0] = newChange;
		
	printf("EUR 환전\n");
	printf("%d 원 -> %d 유로\n", inputWon, finalOutputEUR); // 환전 출력 
	printf("거스름돈 : %d 원\n\n", change / 10 * 10); // 거스름돈 출력
	
		
	for(int i = 0; i < 5; i++) {
		if(coins[i] != 0) printf("%d원: %d 개\n", counts[i], coins[i]);
	}
	printf("\n");
	
	float outputCNY = inputWon / RATE_CNY; // 환전 = 바꾸는 원화 / 환율
	int finalOutputCNY = outputCNY; 
	change = (int) (outputCNY * 100) % 100 * RATE_CNY / 100; // 거스름돈
	
	newChange = change / 10; // 최솟값이 10원단위이기에 	
	for(int i = 4; i > 0; i--) {
		if(i % 2 == 0) {
			int num = newChange % 10; // 10원단위의 값 산출 
			if(num < 5) {
				coins[i] = num;
				coins[i - 1] = 0;
			} else {
				coins[i] = num - 5;
				coins[i - 1] = 1;
			}
			newChange /= 10;
		}
	}
	coins[0] = newChange;
		
	printf("CNY 환전\n");
	printf("%d 원 -> %d 위안\n", inputWon, finalOutputCNY); // 환전 출력 
	printf("거스름돈 : %d 원\n\n", change / 10 * 10); // 거스름돈 출력
	
	for(int i = 0; i < 5; i++) {
		if(coins[i] != 0) printf("%d원: %d 개\n", counts[i], coins[i]);
	}
	printf("\n");
	
	float outputGBP = inputWon / RATE_GBP; // 환전 = 바꾸는 원화 / 환율
	int finalOutputGBP = outputGBP; 
	change = (int) (outputGBP * 100) % 100 * RATE_GBP / 100; // 거스름돈
	
	newChange = change / 10; // 최솟값이 10원단위이기에 	
	for(int i = 4; i > 0; i--) {
		if(i % 2 == 0) {
			int num = newChange % 10; // 10원단위의 값 산출 
			if(num < 5) {
				coins[i] = num;
				coins[i - 1] = 0;
			} else {
				coins[i] = num - 5;
				coins[i - 1] = 1;
			}
			newChange /= 10;
		}
	}
	coins[0] = newChange;
	
	printf("GBP 환전\n");
	printf("%d 원 -> %d 파운드\n", inputWon, finalOutputUSD); // 환전 출력 
	printf("거스름돈 : %d 원\n\n", change / 10 * 10); // 거스름돈 출력
			
	for(int i = 0; i < 5; i++) {
		if(coins[i] != 0) printf("%d원: %d 개\n", counts[i], coins[i]);
	}
	printf("\n");
	
	return 0;
}
