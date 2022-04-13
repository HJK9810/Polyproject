#include <stdio.h>

int main() {
	int number = 0;
	printf("몇 단을 보시겠습니까? : ");
	scanf("%d", &number);
	
	for(int idx = 1; idx < 10; idx++) {
		printf("%d * %d = %d\n", number, idx, number * idx);
	}	
	
	return 0;
}
