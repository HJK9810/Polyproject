#include <stdio.h>
#include <limits.h> // �ڷ����� �ּ�, �ִ� ���� 

int main() {
	int number = 0;
	int min = INT_MAX; // int�� �ִ� 
	int max = INT_MIN; // int�� �ּڰ� 
	
	for (int i = 0; i < 5; i++) { // ���ϰ��� �ݺ��̱⿡ �ݺ��� ��� 
		// A�� �ƽ�Ű�ڵ� + i�� = ���ϴ� ���ĺ� => A, B, C .... 
		printf("���� %c �Է� : ", (char) ((int)'A' + i)); 
		scanf("%d", &number); // ���ϴ� ���� �Է�
		
		if(min > number) min = number; // min�� �Է¹��� �� ���� Ŭ��� ��ü
		if(max < number) max = number; // max���� �Է¹��� �� ���� ������� ��ü 
	}
	
	printf("\n");
	printf("�ִ밪�� %d�Դϴ�. \n", max);
	printf("�ּڰ��� %d�Դϴ�. \n", min);
	
	return 0;
} 
