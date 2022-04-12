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
	
	printf("ȯ���� ���ϴ� �ݾ��� �Է��ϼ���(��ȭ) : ");
	scanf("%d", &inputWon);
	printf("\n");
	printf("ȯ���� ��ȭ�� �����ϼ��� (1:USD, 2:JPY, 3:EUR, 4:CNY, 5:GBP) : ");
	scanf("%d", &input);
	printf("\n");
	
	if(input == 1) { // USD
		float outputUSD = inputWon / RATE_USD; // ȯ�� = �ٲٴ� ��ȭ / ȯ��
		int finalOutputUSD = outputUSD; 
		change = (int) (outputUSD * 100) % 100 * RATE_USD / 100; // �Ž�����
		
		printf("USD ȯ��\n");
		printf("%d �� -> %d �޷�\n", inputWon, finalOutputUSD); // ȯ�� ��� 
	} else if(input == 2) { // JPY
		float outputJPY = inputWon / RATE_JPY; // ȯ�� = �ٲٴ� ��ȭ / ȯ��
		int finalOutputJPY = outputJPY; 
		change = (int) (outputJPY * 100) % 100 * RATE_JPY; // �Ž�����
			
		printf("JPY ȯ��\n");
		printf("%d �� -> %d ��\n", inputWon, finalOutputJPY); // ȯ�� ��� 
	} else if(input == 3) { // EUR
		float outputEUR = inputWon / RATE_EUR; // ȯ�� = �ٲٴ� ��ȭ / ȯ��
		int finalOutputEUR = outputEUR; 
		change = (int) (outputEUR * 100) % 100 * RATE_EUR / 100; // �Ž�����
			
		printf("EUR ȯ��\n");
		printf("%d �� -> %d ����\n", inputWon, finalOutputEUR); // ȯ�� ��� 
	} else if (input == 4) { // CNY
		float outputCNY = inputWon / RATE_CNY; // ȯ�� = �ٲٴ� ��ȭ / ȯ��
		int finalOutputCNY = outputCNY; 
		change = (int) (outputCNY * 100) % 100 * RATE_CNY / 100; // �Ž�����
			
		printf("CNY ȯ��\n");
		printf("%d �� -> %d ����\n", inputWon, finalOutputCNY); // ȯ�� ��� 
	} else if(input == 5) { // GBP
		float outputGBP = inputWon / RATE_GBP; // ȯ�� = �ٲٴ� ��ȭ / ȯ��
		int finalOutputGBP = outputGBP; 
		change = (int) (outputGBP * 100) % 100 * RATE_GBP / 100; // �Ž�����
		
		printf("GBP ȯ��\n");
		printf("%d �� -> %d �Ŀ��\n", inputWon, finalOutputGBP); // ȯ�� ��� 
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
	
	printf("�Ž����� : %d ��\n\n", change / 10 * 10); // �Ž����� ���
	printf("1000�� %d��. 500�� %d��. 100�� %d��. 50�� %d��. 10�� %d��.", return1000, return500, return100, return50, return10);
	
	return 0;
}
