#include <stdio.h>

int calExchange(float rate, int inputWon) {
	float output = inputWon / rate; // 환전 = 바꾸는 원화 / 환율
	return (int) (output * 100) % 100 * rate / 100; // 거스름돈
}

void changeCoins(int money) { // 거스름돈 지불 
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

void changeExchan(int money, char unit[], int input) { // 환전값, 해당 외화의 단위,  외화종류 
	int return5000; // 엔화만 존재 
	int return1000; // 앤화만 존재 
	int return500; // 앤화만 존재 
	int return100; // 파운드만 존재하지 않음 
	int return50;
	int return20; // 엔화만 존재하지 않음 
	int return10;
	int return5;
	
	if(input == 2) { // 엔화만 500엔권 이상이 존재 
		return5000 = money / 5000;
		money -= return5000 * 5000;
		return1000 = money / 1000;
		money -= return1000 * 1000;
		return500 = money / 500;
		money -= return500 * 500;		
	}

	if(input != 5) { // 파운드는 50파운드 이상이 없음 
		return100 = money / 100;
		money -= return100 * 100;	
	}
	
	return50 = money / 50;
	money -= return50 * 50;
	
	if(input != 2) { // 엔화 이외 외화만 20 짜리가 존재 
		return20 = money / 20;
		money -= return20 * 20;	
	}
	
	return10 = money / 10;
	money -= return10 * 10;
	return5 = money / 5;
	money -= return5 * 5; // 남은 money = 단위가 1인 외화 지불수량 
	
	// pirnt 영역 
	if(input == 2) { // 엔화만 존재 
		printf("5000%s %d개. ", unit, return5000);
		printf("1000%s %d개. ", unit, return1000);	
		printf("500%s %d개. ", unit, return500);	
	}
	
	if(input != 5) { // 파운드는 50파운드 이상이 없음 
		printf("100%s %d개. ", unit, return100);	
	}
	
	printf("50%s %d개. ", unit, return50);

	if(input != 2) { // 엔화 이외만 20 짜리가 존재
		printf("20%s %d개. ", unit, return20);	
	}
	
	printf("10%s %d개. ", unit, return10);
	printf("5%s %d개. ", unit, return5);
	printf("1%s %d개. ", unit, money);
	
	printf("\n");
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
	
	int change = calExchange(rate, inputWon); // 환전되고 남은 거스름돈 
	int exchange = inputWon / rate; // 환전된값 
	
	// 출력 
	printf("환전결과\n");
	printf("%d 원 -> %d", inputWon, exchange); // 환전 출력
	
	switch(input) { // 외화 단위 출력 & 해당 외화 지불방법 
		case 1: // USD
			printf("달러\n");
			changeExchan(exchange, "달러", input);
			break;
		case 2: // JPY
			printf("엔\n");
			changeExchan(exchange, "엔", input);
			break;
		case 3: // EUR
			printf("유로\n");
			changeExchan(exchange, "유로", input);
			break;
		case 4: // CNY
			printf("위안\n");
			changeExchan(exchange, "위안", input); 
			break;
		case 5: // GBP
			printf("파운드\n");
			changeExchan(exchange, "파운드", input);
			break;
		default:
			break;
	}
	
	printf("\n");
	printf("거스름돈 : %d 원\n", change / 10 * 10); // 거스름돈 출력
	changeCoins(change); // 거스름돈 분리 출력 
	
	return 0;
}
