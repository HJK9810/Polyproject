#include <stdio.h>

int main() { // ������ ���������� ��� 
	int number = 0;
	int size = 0;
	
	printf("����� ���ϴ� ���� �Է��ϼ��� : ");
	scanf("%d", &number);
	printf("���ٿ� ��µǱ� ���ϴ� ũ�⸦ �����ϼ��� : ");
	scanf("%d", &size);
	
	for(int idx = 0; idx < size / 2 + 1; idx++) printf("\t");
	
	printf("===������===\n\n");
	
	for(int idx = 2; idx < number + 1; idx += size) { // 5�ܾ� �������� 
		for(int jdx = 1; jdx < 10; jdx++) { // \t = �� �ϳ� ����, \n = �ٹٲ�
			for(int line = 0; line < size; line++) {
				if((idx + line) > number) break;
				
				printf("%d * %d = %d\t", idx + line, jdx, (idx + line) * jdx);
			}
			printf("\n");
		}
		printf("\n");
	}	
	
	return 0;
}
