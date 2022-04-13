#include <stdio.h>

int main() {
	printf("===±¸±¸´Ü===\n");
	
	for(int idx = 2; idx < 10; idx++) {
		for(int jdx = 1; jdx < 10; jdx++) {
			printf("%d * %d = %d\n", idx, jdx, idx * jdx);
		}
		printf("\n");
	}	
	
	return 0;
}
