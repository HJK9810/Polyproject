#include <stdio.h>

void changeCoins(int money) {
	const int counts[5] = {1000, 500, 100, 50, 10};
	
	for(int i = 0; i < 5; i++) {
		int coin = money / counts[i];
		money -= coin * counts[i];
		
		if(coin != 0) printf("%d��: %d ��. ", counts[i], coin);
	}
	
	printf("\n");
}

int main() {
	int inputWon = 0;
	int input = 0;
		
	const float RATE[] = {1233.1, 9.87, 1342.79, 193.25, 1605.28};
	const char UNIT[][10] = {"�޷�", "��", "����", "����", "�Ŀ��"};
	
	printf("ȯ���� ���ϴ� �ݾ��� �Է��ϼ���(��ȭ) : ");
	scanf("%d", &inputWon);
	
	do{ // �־��� ��� �ܸ̿� �Է��Ұ�� �ݺ� 
		printf("ȯ���� ��ȭ�� �����ϼ��� (1:USD, 2:JPY, 3:EUR, 4:CNY, 5:GBP) : ");
		scanf("%d", &input);
	} while (input < 1 || input > 5);
	
	const float rate = RATE[input - 1]; // �ش� ȯ�� �Է� 
	
	float output = inputWon / rate; // ȯ�� = �ٲٴ� ��ȭ / ȯ��
	int change = (int) (output * 100) % 100 * rate / 100; // �Ž�����
	
	printf("���� ȯ�� : %.2f\n\n", rate); // ��� ȯ���� �Ҽ��� ��°¥�������⿡ .2f ��� 
	printf("ȯ�����\n");
	printf("%d �� -> %d %s\n", inputWon, (int) output, UNIT[input - 1]); // ȯ�� ��� 
	printf("�Ž����� : %d ��\n", change / 10 * 10); // �Ž����� ��� - 1������ ���� 
	printf("1�������� �Ž����� : %d ��\n\n", change); // �Ž����� ��� - 1���������� ��� 
	changeCoins(change);
	
	return 0;
}
