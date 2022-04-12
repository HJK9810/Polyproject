#include <stdio.h>

int main() {
	const float RATE_USD = 1233.1;
	const float RATE_JPY = 9.87;
	const float RATE_EUR = 1342.79;
	const float RATE_CNY = 193.25;
	const float RATE_GBP = 1605.28;
	int inputWon = 0; // ��ȭ 
	int change  = 0; // �Ž����� 
	int input = 0; // ���ϴ� ��ȭ ���ÿ� 
	int return1000;
	int return500;
	int return100;
	int return50;
	int return10;
	int newChange = 0; // ��������� ���� �Ž�����
	float rate = 0.0;
	const char UNIT[][10] = {"�޷�", "��", "����", "����", "�Ŀ��"};
	
	printf("ȯ���� ���ϴ� �ݾ��� �Է��ϼ���(��ȭ) : ");
	scanf("%d", &inputWon);
	printf("\n");
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
	
	float output = inputWon / rate; // ȯ�� = �ٲٴ� ��ȭ / ȯ��
	int finalOutput = output; 
	change = (int) (output * 100) % 100 * rate / 100; // �Ž�����
	
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
	
	printf("ȯ�����\n");
	printf("%d �� -> %d %s\n", inputWon, finalOutput, UNIT[input - 1]); // ȯ�� ��� 
	printf("�Ž����� : %d ��\n\n", change / 10 * 10); // �Ž����� ���
	printf("1000�� %d��. 500�� %d��. 100�� %d��. 50�� %d��. 10�� %d��.", return1000, return500, return100, return50, return10);
	
	return 0;
}
