#include <stdio.h>

int main() {
	int year = 0;
	
	printf("���ϴ� �⵵�� �Է��ϼ��� : ");
	scanf("%d", &year);
	// ������ ���� : 4�� ������� 100�� ����� �ƴҶ� or 400�� ����϶� 
	if (year % 4 == 0 && year % 100 != 0) {
		printf("���� �Դϴ�.\n");
	} else if(year % 400 == 0) {
		printf("���� �Դϴ�. \n");
	} else {
		printf("������ �ƴմϴ�.\n");
	}
	
	return 0;
}
