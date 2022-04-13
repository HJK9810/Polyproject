#include <stdio.h>

int main() {
	for(int index = 0; index < 5; index++) {
		int num1, num2;
		char oper;
		printf("%d번째, 수식을 입력하세요 : ", index + 1);
		scanf("%d%c%d", &num1, &oper, &num2);
		int result;
		
		if(oper == '+') { // 수식 기호가 +일경우 
			printf("%d + %d = %d\n", num1, num2, num1 + num2);
		} else if(oper == '-') { // 수식 기호가 -일경우 
			printf("%d - %d = %d\n", num1, num2, num1 - num2);
		} else if(oper == '*') { // 수식 기호가 *일경우 
			printf("%d * %d = %d\n", num1, num2, num1 * num2);
		} else if(oper == '/') { // 수식 기호가 /일경우 
			printf("%d / %d = %d\n", num1, num2, num1 / num2);
		} else if(oper == '^') { // 수식 기호가 ^일경우 
			result = num1; // 결과 
			for(int idx = 0; idx < num2 - 1; idx++) { // ^기호 = 제곱
				result *= num1;
			}
			printf("%d^%d = %d\n", num1, num2, result);
		} else { // 수식 기호가 어디에도 해당하지 않을 경우 
			printf("잘못된 수식입니다. \n");
		}
	}
}
