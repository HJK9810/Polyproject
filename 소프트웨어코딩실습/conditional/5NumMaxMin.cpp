#include <stdio.h> 

int main() {
	int number = 0;
	int min; // int�� �ִ� 
	int max; // int�� �ּڰ� 
	
	printf("����A �Է� : "); 
	scanf("%d", &number); // ���ϴ� ���� �Է�
	max = number;
	min = number;
	
	printf("����B �Է� : "); 
	scanf("%d", &number); // ���ϴ� ���� �Է�
	if(min > number) min = number; // min�� �Է¹��� �� ���� Ŭ��� ��ü
	if(max < number) max = number; // max���� �Է¹��� �� ���� ������� ��ü 
	
	printf("����C �Է� : "); 
	scanf("%d", &number); // ���ϴ� ���� �Է�
	if(min > number) min = number; // min�� �Է¹��� �� ���� Ŭ��� ��ü
	if(max < number) max = number; // max���� �Է¹��� �� ���� ������� ��ü 
	
	printf("����D �Է� : "); 
	scanf("%d", &number); // ���ϴ� ���� �Է�
	if(min > number) min = number; // min�� �Է¹��� �� ���� Ŭ��� ��ü
	if(max < number) max = number; // max���� �Է¹��� �� ���� ������� ��ü 
	
	printf("����E �Է� : "); 
	scanf("%d", &number); // ���ϴ� ���� �Է�
	if(min > number) min = number; // min�� �Է¹��� �� ���� Ŭ��� ��ü
	if(max < number) max = number; // max���� �Է¹��� �� ���� ������� ��ü 
	
	printf("\n");
	printf("�ִ밪�� %d�Դϴ�. \n", max);
	printf("�ּڰ��� %d�Դϴ�. \n", min);
	
	return 0;
} 
