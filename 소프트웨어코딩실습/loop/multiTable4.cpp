#include <stdio.h>

int main() {
	printf("===������===\n\n");
	
	for(int idx = 2; idx < 11; idx++) {
		
		printf("==%d��==\n\n", idx);
		
		if(idx % 3 == 0) printf("�̾�~ Skip~!\n");
		else {
			for(int jdx = 1; jdx < 11; jdx++) { // \n = �ٹٲ� 
			printf("%d * %d = %d\n", idx, jdx, idx * jdx); 
			}
		}
		printf("\n");
	}	
	
	return 0;
}
