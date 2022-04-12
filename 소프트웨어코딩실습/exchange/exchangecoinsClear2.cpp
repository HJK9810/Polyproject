#include <stdio.h>
#include <string.h>

void changeCoins(int money) {
	const int counts[5] = {1000, 500, 100, 50, 10};
	
	for(int i = 0; i < 5; i++) {
		int coin = money / counts[i];
		money -= coin * counts[i];
		// ���ҵǴ� ������ ��� 
		if(coin != 0) printf("%d��: %d ��. ", counts[i], coin);
	}
	
	printf("\n\n");
}

void changeExchan(int money, char unit[], int input) {
	const int counts[9] = {5000, 1000, 500, 100, 50, 20, 10, 5, 1};
	
	for(int i = 0; i < 9; i++) {
		if(input != 2 && i < 3) continue; // ��ȭ�� 5000, 1000, 500�� ���� 
		if(input == 5 && i == 3) continue; // �Ŀ��� 100�Ŀ�� �̻� ����X 
		if(input == 2 && i == 5) continue; // ��ȭ�� 20�� ���� 
		
		int coin = money / counts[i];
		money -= coin * counts[i];
		// ���ҵǴ� ������ ��� 
		if(coin != 0) printf("%d%s: %d ��. ", counts[i], unit, coin);
	}
	
	printf("\n\n");
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
	char unit[10];
	strcpy(unit, UNIT[input - 1]); // ������ �����ϱ� ���� ������ 
	
	changeExchan((int) output, unit, input); // ��ȭ ���� ���� 
	
	printf("�Ž����� : %d ��\n", change / 10 * 10); // �Ž����� ��� - 1������ ���� 
	printf("1�������� �Ž����� : %d ��\n", change); // �Ž����� ��� - 1���������� ��� 
	changeCoins(change); // �Ž����� ���� ���� 
	
	return 0;
}
