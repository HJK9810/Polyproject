#include <stdio.h>

int calExchange(float rate, int inputWon) {
	float output = inputWon / rate; // ȯ�� = �ٲٴ� ��ȭ / ȯ��
	return (int) (output * 100) % 100 * rate / 100; // �Ž�����
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
	
	printf("1000�� %d��. 500�� %d��. 100�� %d��. 50�� %d��. 10�� %d��.", return1000, return500, return100, return50, return10);
}

int main() {
	const float RATE_USD = 1233.1;
	const float RATE_JPY = 9.87;
	const float RATE_EUR = 1342.79;
	const float RATE_CNY = 193.25;
	const float RATE_GBP = 1605.28;
	int inputWon = 0; // ��ȭ 
	int input = 0; // ���ϴ� ��ȭ ���ÿ�
	float rate = 0.0;
	
	printf("ȯ���� ���ϴ� �ݾ��� �Է��ϼ���(��ȭ) : ");
	scanf("%d", &inputWon);
	printf("ȯ���� ��ȭ�� �����ϼ��� (1:USD, 2:JPY, 3:EUR, 4:CNY, 5:GBP) : ");
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
	
	// ��� 
	printf("ȯ�����\n");
	printf("%d �� -> %d ", inputWon, (int) (inputWon / rate)); // ȯ�� ���
	
	switch(input) {
		case 1: // USD
			printf("�޷�\n");
			break;
		case 2: // JPY
			printf("��\n");
			break;
		case 3: // EUR
			printf("����\n");
			break;
		case 4: // CNY
			printf("����\n");
			break;
		case 5: // GBP
			printf("�Ŀ��\n");
			break;
		default:
			break;
	}

	printf("�Ž����� : %d ��\n\n", change / 10 * 10); // �Ž����� ���
	changCoins(change);
	
	return 0;
}
