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
	
	printf("ȯ���� ���ϴ� �ݾ��� �Է��ϼ���(��ȭ) : ");
	scanf("%d", &inputWon);
	printf("\n");
	
	float outputUSD = inputWon / RATE_USD; // ȯ�� = �ٲٴ� ��ȭ / ȯ��
	int finalOutputUSD = outputUSD; 
	change = (int) (outputUSD * 100) % 100 * RATE_USD / 100; // �Ž�����
	
	newChange = change / 10; // �ּڰ��� 10�������̱⿡ 	
	for(int i = 4; i > 0; i--) {
		if(i % 2 == 0) {
			int num = newChange % 10; // 10�������� �� ���� 
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
	
	printf("USD ȯ��\n");
	printf("%d �� -> %d �޷�\n", inputWon, finalOutputUSD); // ȯ�� ��� 
	printf("�Ž����� : %d ��\n", change / 10 * 10); // �Ž����� ��� 
	
	for(int i = 0; i < 5; i++) {
		if(coins[i] != 0) printf("%d��: %d ��\n", counts[i], coins[i]);
	}
	printf("\n");
	
	float outputJPY = inputWon / RATE_JPY; // ȯ�� = �ٲٴ� ��ȭ / ȯ��
	int finalOutputJPY = outputJPY; 
	change = (int) (outputJPY * 100) % 100 * RATE_JPY; // �Ž�����
	
	newChange = change / 10; // �ּڰ��� 10�������̱⿡ 	
	for(int i = 4; i > 0; i--) {
		if(i % 2 == 0) {
			int num = newChange % 10; // 10�������� �� ���� 
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
		
	printf("JPY ȯ��\n");
	printf("%d �� -> %d ��\n", inputWon, finalOutputJPY); // ȯ�� ��� 
	printf("�Ž����� : %d ��\n\n", change / 10 * 10); // �Ž����� ���
		
	for(int i = 0; i < 5; i++) {
		if(coins[i] != 0) printf("%d��: %d ��\n", counts[i], coins[i]);
	}
	printf("\n");
	
	float outputEUR = inputWon / RATE_EUR; // ȯ�� = �ٲٴ� ��ȭ / ȯ��
	int finalOutputEUR = outputEUR; 
	change = (int) (outputEUR * 100) % 100 * RATE_EUR / 100; // �Ž�����
	
	newChange = change / 10; // �ּڰ��� 10�������̱⿡ 	
	for(int i = 4; i > 0; i--) {
		if(i % 2 == 0) {
			int num = newChange % 10; // 10�������� �� ���� 
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
		
	printf("EUR ȯ��\n");
	printf("%d �� -> %d ����\n", inputWon, finalOutputEUR); // ȯ�� ��� 
	printf("�Ž����� : %d ��\n\n", change / 10 * 10); // �Ž����� ���
	
		
	for(int i = 0; i < 5; i++) {
		if(coins[i] != 0) printf("%d��: %d ��\n", counts[i], coins[i]);
	}
	printf("\n");
	
	float outputCNY = inputWon / RATE_CNY; // ȯ�� = �ٲٴ� ��ȭ / ȯ��
	int finalOutputCNY = outputCNY; 
	change = (int) (outputCNY * 100) % 100 * RATE_CNY / 100; // �Ž�����
	
	newChange = change / 10; // �ּڰ��� 10�������̱⿡ 	
	for(int i = 4; i > 0; i--) {
		if(i % 2 == 0) {
			int num = newChange % 10; // 10�������� �� ���� 
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
		
	printf("CNY ȯ��\n");
	printf("%d �� -> %d ����\n", inputWon, finalOutputCNY); // ȯ�� ��� 
	printf("�Ž����� : %d ��\n\n", change / 10 * 10); // �Ž����� ���
	
	for(int i = 0; i < 5; i++) {
		if(coins[i] != 0) printf("%d��: %d ��\n", counts[i], coins[i]);
	}
	printf("\n");
	
	float outputGBP = inputWon / RATE_GBP; // ȯ�� = �ٲٴ� ��ȭ / ȯ��
	int finalOutputGBP = outputGBP; 
	change = (int) (outputGBP * 100) % 100 * RATE_GBP / 100; // �Ž�����
	
	newChange = change / 10; // �ּڰ��� 10�������̱⿡ 	
	for(int i = 4; i > 0; i--) {
		if(i % 2 == 0) {
			int num = newChange % 10; // 10�������� �� ���� 
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
	
	printf("GBP ȯ��\n");
	printf("%d �� -> %d �Ŀ��\n", inputWon, finalOutputUSD); // ȯ�� ��� 
	printf("�Ž����� : %d ��\n\n", change / 10 * 10); // �Ž����� ���
			
	for(int i = 0; i < 5; i++) {
		if(coins[i] != 0) printf("%d��: %d ��\n", counts[i], coins[i]);
	}
	printf("\n");
	
	return 0;
}
