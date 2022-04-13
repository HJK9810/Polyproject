#include <stdio.h>
#include <limits.h> // 자료형의 최소, 최댓값 정의 

int main() {
	int number = 0;
	int min = INT_MAX; // int의 최댓값 
	int max = INT_MIN; // int의 최솟값 
	
	for (int i = 0; i < 5; i++) { // 동일과정 반복이기에 반복문 사용 
		// A의 아스키코드 + i값 = 원하는 알파벳 => A, B, C .... 
		printf("숫자 %c 입력 : ", (char) ((int)'A' + i)); 
		scanf("%d", &number); // 원하는 숫자 입력
		
		if(min > number) min = number; // min이 입력받은 값 보다 클경우 대체
		if(max < number) max = number; // max값이 입력받은 값 보다 작을경우 대체 
	}
	
	printf("\n");
	printf("최대값은 %d입니다. \n", max);
	printf("최솟값은 %d입니다. \n", min);
	
	return 0;
} 
