#include <stdio.h>

int main() {
	int subject = 0;
	int students = 0;
	printf("���� �� �Է� : ");
	scanf("%d", &subject);
	printf("�л� �� �Է� : ");
	scanf("%d", &students);
	
	int score[students][subject] = {0};
	int sum[students] = {0};
	float ave[students] = {0};
	float subjectAve[subject] = {0};
	// �Է� 
	for(int idx = 0; idx < students; idx++) {
		printf("Koposw%d �л��� ���� %d���� ���ʴ�� �Է��ϼ���. : ", idx + 1, subject);
		for(int jdx = 0; jdx < subject; jdx++) {
			scanf("%d", &score[idx][jdx]);
		}
	}
	
	// ���
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
	
	// ��� 
	printf("\n");
	for(int idx = 0; idx < students; idx++) {
		printf("Koposw%d �л��� ���� ������ %d��, ����� %.2f �Դϴ�. \n", idx + 1, sum[idx], ave[idx]);
	}
	printf("\n");
	for(int idx = 0; idx < subject; idx++) {
		printf("���� %d ��ü ��� : %.2f��\n", idx + 1, subjectAve[idx]);
	}
	
	return 0;
}
