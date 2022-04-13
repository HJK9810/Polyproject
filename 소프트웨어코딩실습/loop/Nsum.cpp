#include <stdio.h>

int main() {
	int number = 0;
	int sum = 0;
	// 1~100까지의 합 
	for(int idx = 1 ; idx < 101; idx++) {
		sum += idx;
	}	
	printf("1에서 100까지 합은 %d입니다.\n", sum);
	
	// 1~N 까지의 합 
	printf("N을 입력하세요 : ");
	scanf("%d", &number);
	
	// for문 이용 
	for(int idx = 1 ; idx < number + 1; idx++) {
		sum += idx;
	}	
	printf("for문 - 1에서 %d까지 합은 %d입니다.\n", number, sum);
	
	// 합 공식 이용 
	sum = number * (number + 1) / 2;
	printf("합공식 - 1에서 %d까지 합은 %d입니다.\n", number, sum);
	
	return 0;
}
