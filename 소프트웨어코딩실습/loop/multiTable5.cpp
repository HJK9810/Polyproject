#include <stdio.h>

int main() { // 구구단 가변적으로 출력 
	int number = 0;
	int size = 0;
	
	printf("출력을 원하는 단을 입력하세요 : ");
	scanf("%d", &number);
	printf("한줄에 출력되길 원하는 크기를 선택하세요 : ");
	scanf("%d", &size);
	
	for(int idx = 0; idx < size / 2 + 1; idx++) printf("\t");
	
	printf("===구구단===\n\n");
	
	for(int idx = 2; idx < number + 1; idx += size) { // 5단씩 끊기위해 
		for(int jdx = 1; jdx < 10; jdx++) { // \t = 탭 하나 띄어쓰기, \n = 줄바꿈
			for(int line = 0; line < size; line++) {
				if((idx + line) > number) break;
				
				printf("%d * %d = %d\t", idx + line, jdx, (idx + line) * jdx);
			}
			printf("\n");
		}
		printf("\n");
	}	
	
	return 0;
}
