#include <stdio.h>

int main() {
	int year;
	int day = 28; // 2�� ��¥ : ���� = 29, ��� = 28 
	
	printf("���ϴ� ������ �Է��ϼ��� : ");
	scanf("%d", &year);
	
	// ������ ���� : 4�� ������� 100�� ����� �ƴҶ� or 400�� ����϶� 
	if (year % 4 == 0 && year % 100 != 0) day = 29;
	else if(year % 400 == 0) day = 29;
	
	// �ش� �⵵ ��� 
	printf("%d���� ������ �����ϴ�.\n", year);
	
	printf("1�� : 31��\n");
	printf("2�� : %d�� * ���� 29�� , ��� 28��\n", day);
	printf("3�� : 31��\n");
	printf("4�� : 30��\n");
	printf("5�� : 31��\n");
	printf("6�� : 30��\n");
	printf("7�� : 31��\n");
	printf("8�� : 31��\n");
	printf("9�� : 30��\n");
	printf("10�� : 31��\n");
	printf("11�� : 30��\n");
	printf("12�� : 31��\n");

	return 0;
} 
