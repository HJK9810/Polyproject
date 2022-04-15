#include <stdio.h>

int main() {
	int subject = 0;
	int students = 0;
	printf("과목 수 입력 : ");
	scanf("%d", &subject);
	printf("학생 수 입력 : ");
	scanf("%d", &students);
	
	int score[students][subject] = {0};
	int sum[students] = {0};
	float ave[students] = {0};
	float subjectAve[subject] = {0};
	// 입력 
	for(int idx = 0; idx < students; idx++) {
		printf("Koposw%d 학생의 점수 %d개를 차례대로 입력하세요. : ", idx + 1, subject);
		for(int jdx = 0; jdx < subject; jdx++) {
			scanf("%d", &score[idx][jdx]);
		}
	}
	
	// 계산
	for(int idx = 0; idx < students; idx++) {
		for(int jdx = 0; jdx < subject; jdx++) {
			int grade = score[idx][jdx];
			sum[idx] += grade;
			subjectAve[jdx] += grade;
		}
		ave[idx] = (float) sum[idx] / subject;
	}
	
	for(int idx = 0; idx < subject; idx++) {
		subjectAve[idx] = subjectAve[idx] / students;
	}
	
	// 출력 
	printf("\n");
	for(int idx = 0; idx < students; idx++) {
		printf("Koposw%d 학생의 과목 총점은 %d점, 평균은 %.2f 입니다. \n", idx + 1, sum[idx], ave[idx]);
	}
	printf("\n");
	for(int idx = 0; idx < subject; idx++) {
		printf("과목 %d 전체 평균 : %.2f점\n", idx + 1, subjectAve[idx]);
	}
	
	return 0;
}
