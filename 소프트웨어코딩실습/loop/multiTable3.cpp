#include <stdio.h>

int main() {
	printf("\t\t===������===\n\n");
	
	for(int idx = 2; idx < 10; idx += 3) { // 3�ܾ� �������� +3 
		for(int jdx = 1; jdx < 10; jdx++) { // \t = �� �ϳ� ����, \n = �ٹٲ� 
			printf("%d * %d = %d\t", idx, jdx, idx * jdx); // 2, 5, 8�� 
			printf("%d * %d = %d\t", idx + 1, jdx, (idx + 1) * jdx); // 3, 6, 9�� 
			printf("%d * %d = %d\n", idx + 2, jdx, (idx + 2) * jdx); // 4, 7, 10�� 
		}
		printf("\n");
	}	
	
	return 0;
}
