#include <stdio.h>

int main() {
	for(int index = 0; index < 5; index++) {
		int num1, num2;
		char oper;
		printf("%d��°, ������ �Է��ϼ��� : ", index + 1);
		scanf("%d%c%d", &num1, &oper, &num2);
		int result;
		
		if(oper == '+') { // ���� ��ȣ�� +�ϰ�� 
			printf("%d + %d = %d\n", num1, num2, num1 + num2);
		} else if(oper == '-') { // ���� ��ȣ�� -�ϰ�� 
			printf("%d - %d = %d\n", num1, num2, num1 - num2);
		} else if(oper == '*') { // ���� ��ȣ�� *�ϰ�� 
			printf("%d * %d = %d\n", num1, num2, num1 * num2);
		} else if(oper == '/') { // ���� ��ȣ�� /�ϰ�� 
			printf("%d / %d = %d\n", num1, num2, num1 / num2);
		} else if(oper == '^') { // ���� ��ȣ�� ^�ϰ�� 
			result = num1; // ��� 
			for(int idx = 0; idx < num2 - 1; idx++) { // ^��ȣ = ����
				result *= num1;
			}
			printf("%d^%d = %d\n", num1, num2, result);
		} else { // ���� ��ȣ�� ��𿡵� �ش����� ���� ��� 
			printf("�߸��� �����Դϴ�. \n");
		}
	}
}
