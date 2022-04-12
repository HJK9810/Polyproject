#include <stdio.h>

int calExchange(float rate, int inputWon) {
	float output = inputWon / rate; // ȯ�� = �ٲٴ� ��ȭ / ȯ��
	return (int) (output * 100) % 100 * rate / 100; // �Ž�����
}

void changeCoins(int money) { // �Ž����� ���� 
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

void changeExchan(int money, char unit[], int input) { // ȯ����, �ش� ��ȭ�� ����,  ��ȭ���� 
	int return5000; // ��ȭ�� ���� 
	int return1000; // ��ȭ�� ���� 
	int return500; // ��ȭ�� ���� 
	int return100; // �Ŀ�常 �������� ���� 
	int return50;
	int return20; // ��ȭ�� �������� ���� 
	int return10;
	int return5;
	
	if(input == 2) { // ��ȭ�� 500���� �̻��� ���� 
		return5000 = money / 5000;
		money -= return5000 * 5000;
		return1000 = money / 1000;
		money -= return1000 * 1000;
		return500 = money / 500;
		money -= return500 * 500;		
	}

	if(input != 5) { // �Ŀ��� 50�Ŀ�� �̻��� ���� 
		return100 = money / 100;
		money -= return100 * 100;	
	}
	
	return50 = money / 50;
	money -= return50 * 50;
	
	if(input != 2) { // ��ȭ �̿� ��ȭ�� 20 ¥���� ���� 
		return20 = money / 20;
		money -= return20 * 20;	
	}
	
	return10 = money / 10;
	money -= return10 * 10;
	return5 = money / 5;
	money -= return5 * 5; // ���� money = ������ 1�� ��ȭ ���Ҽ��� 
	
	// pirnt ���� 
	if(input == 2) { // ��ȭ�� ���� 
		printf("5000%s %d��. ", unit, return5000);
		printf("1000%s %d��. ", unit, return1000);	
		printf("500%s %d��. ", unit, return500);	
	}
	
	if(input != 5) { // �Ŀ��� 50�Ŀ�� �̻��� ���� 
		printf("100%s %d��. ", unit, return100);	
	}
	
	printf("50%s %d��. ", unit, return50);

	if(input != 2) { // ��ȭ �ܸ̿� 20 ¥���� ����
		printf("20%s %d��. ", unit, return20);	
	}
	
	printf("10%s %d��. ", unit, return10);
	printf("5%s %d��. ", unit, return5);
	printf("1%s %d��. ", unit, money);
	
	printf("\n");
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
	
	int change = calExchange(rate, inputWon); // ȯ���ǰ� ���� �Ž����� 
	int exchange = inputWon / rate; // ȯ���Ȱ� 
	
	// ��� 
	printf("ȯ�����\n");
	printf("%d �� -> %d", inputWon, exchange); // ȯ�� ���
	
	switch(input) { // ��ȭ ���� ��� & �ش� ��ȭ ���ҹ�� 
		case 1: // USD
			printf("�޷�\n");
			changeExchan(exchange, "�޷�", input);
			break;
		case 2: // JPY
			printf("��\n");
			changeExchan(exchange, "��", input);
			break;
		case 3: // EUR
			printf("����\n");
			changeExchan(exchange, "����", input);
			break;
		case 4: // CNY
			printf("����\n");
			changeExchan(exchange, "����", input); 
			break;
		case 5: // GBP
			printf("�Ŀ��\n");
			changeExchan(exchange, "�Ŀ��", input);
			break;
		default:
			break;
	}
	
	printf("\n");
	printf("�Ž����� : %d ��\n", change / 10 * 10); // �Ž����� ���
	changeCoins(change); // �Ž����� �и� ��� 
	
	return 0;
}
