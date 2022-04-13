#include <stdio.h>

int main() {
	printf("===구구단===\n\n");
	
	for(int idx = 2; idx < 11; idx++) {
		
		printf("==%d단==\n\n", idx);
		
		if(idx % 3 == 0) printf("미안~ Skip~!\n");
		else {
			for(int jdx = 1; jdx < 11; jdx++) { // \n = 줄바꿈 
			printf("%d * %d = %d\n", idx, jdx, idx * jdx); 
			}
		}
		printf("\n");
	}	
	
	return 0;
}
