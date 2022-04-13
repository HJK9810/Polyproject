#include <stdio.h> 

int main() {
	int number = 0;
	int min; // int의 최댓값 
	int max; // int의 최솟값 
	
	printf("숫자A 입력 : "); 
	scanf("%d", &number); // 원하는 숫자 입력
	max = number;
	min = number;
	
	printf("숫자B 입력 : "); 
	scanf("%d", &number); // 원하는 숫자 입력
	if(min > number) min = number; // min이 입력받은 값 보다 클경우 대체
	if(max < number) max = number; // max값이 입력받은 값 보다 작을경우 대체 
	
	printf("숫자C 입력 : "); 
	scanf("%d", &number); // 원하는 숫자 입력
	if(min > number) min = number; // min이 입력받은 값 보다 클경우 대체
	if(max < number) max = number; // max값이 입력받은 값 보다 작을경우 대체 
	
	printf("숫자D 입력 : "); 
	scanf("%d", &number); // 원하는 숫자 입력
	if(min > number) min = number; // min이 입력받은 값 보다 클경우 대체
	if(max < number) max = number; // max값이 입력받은 값 보다 작을경우 대체 
	
	printf("숫자E 입력 : "); 
	scanf("%d", &number); // 원하는 숫자 입력
	if(min > number) min = number; // min이 입력받은 값 보다 클경우 대체
	if(max < number) max = number; // max값이 입력받은 값 보다 작을경우 대체 
	
	printf("\n");
	printf("최대값은 %d입니다. \n", max);
	printf("최솟값은 %d입니다. \n", min);
	
	return 0;
} 
