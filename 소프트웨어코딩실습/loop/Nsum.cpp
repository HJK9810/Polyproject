#include <stdio.h>

int main() {
	int number = 0;
	int sum = 0;
	// 1~100������ �� 
	for(int idx = 1 ; idx < 101; idx++) {
		sum += idx;
	}	
	printf("1���� 100���� ���� %d�Դϴ�.\n", sum);
	
	// 1~N ������ �� 
	printf("N�� �Է��ϼ��� : ");
	scanf("%d", &number);
	
	// for�� �̿� 
	for(int idx = 1 ; idx < number + 1; idx++) {
		sum += idx;
	}	
	printf("for�� - 1���� %d���� ���� %d�Դϴ�.\n", number, sum);
	
	// �� ���� �̿� 
	sum = number * (number + 1) / 2;
	printf("�հ��� - 1���� %d���� ���� %d�Դϴ�.\n", number, sum);
	
	return 0;
}
