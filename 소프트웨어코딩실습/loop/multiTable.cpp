#include <stdio.h>

int main() {
	int number = 0;
	printf("�� ���� ���ðڽ��ϱ�? : ");
	scanf("%d", &number);
	
	for(int idx = 1; idx < 10; idx++) {
		printf("%d * %d = %d\n", number, idx, number * idx);
	}	
	
	return 0;
}
