#include <stdio.h>

int main() {
	printf("\t\t===구구단===\n\n");
	
	for(int idx = 2; idx < 10; idx += 3) { // 3단씩 끊기위해 +3 
		for(int jdx = 1; jdx < 10; jdx++) { // \t = 탭 하나 띄어쓰기, \n = 줄바꿈 
			printf("%d * %d = %d\t", idx, jdx, idx * jdx); // 2, 5, 8단 
			printf("%d * %d = %d\t", idx + 1, jdx, (idx + 1) * jdx); // 3, 6, 9단 
			printf("%d * %d = %d\n", idx + 2, jdx, (idx + 2) * jdx); // 4, 7, 10단 
		}
		printf("\n");
	}	
	
	return 0;
}
