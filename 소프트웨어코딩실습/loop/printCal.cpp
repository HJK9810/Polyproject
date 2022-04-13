#include <stdio.h>

void print(int day, int date) {
	int line = 0;
	
	for(int idx = 1; idx < date + 1; idx++) {
		if(idx == 1 && line < day) { // �ش� ������ ù ���ϰ� �������� ������ 
			printf("\t");
			idx -= 1; // �� ���� �� ���·� ������ �� 
		} else {
			printf("%4d%4s", idx, " "); // UI�� ���� ��� - ���� ��ĭ + ���� + ��ĭ 4ĭ 
		} 
		line++; // ������ �������� 
		
		if(line == 7) { // ���������Ͽ� ���� 
			printf("\n"); // �ٹٲ� 
			line = 0; // �ʱ�ȭ 
		}
	}
	
	printf("\n\n"); // �޷���� �Ϸ���, ���� �� �޷��� ���� ��ĭ���� 2�� 
}

int main() {
	int year = 1900; // ��ǻ�� �⺻ �⵵ 
	int month = 1;	// ��ǻ�� �⺻ �� 
	
	while(true) { // ���ѷ��� 
		do {
			printf("  �⵵ �Է�(1900��� ���ĸ� �����մϴ�.) : ");
			scanf("%d", &year);
		} while (year < 1900);
		
		if(year == 0) break; // �⵵�� 0�ϰ��, ���ѷ��� ���� 
		
		do {
			printf("  �� �Է�(1 ~ 12���̸� �Է� �����մϴ�.) : ");
			scanf("%d", &month);
		} while (month < 1 || month > 13);
		
		printf("\n\n");	
		
		int count = year - 1900; // 1900��� ���ĸ� ������ ��� 
		int leap = 0; // ����� 
		int common = 0; // ���� 
		
		for(int idx = 0; idx < count; idx++) { 
			int checkY = 1900 + idx; // ������ �˾ƺ��� ���� ���� 
			
			// ������ ���� : 4�� ������� 100�� ����� �ƴҶ� or 400�� ����϶� 
			if (checkY % 4 == 0 && checkY % 100 != 0) leap++;
			else if(checkY % 400 == 0) leap++;
			else common++;
		}
		
		int date = 30;
		int dateSum = 0;
		for(int idx = 1; idx < month + 1; idx++) {
			switch(idx) { // �ش� �� �������� ���ϱ� 
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					date = 31;
					break;
				case 2:
					if (year % 4 == 0 && year % 100 != 0) date = 29;
					else if(year % 400 == 0) date = 29;
					else date = 28;
					break;
				default:
					date = 30;
					break;
			}
			dateSum += date;		
		}
		
		// ������ ���⺸�� ������ ��Ʋ ���̳�����, ����� �Ϸ� ���̳� 
		// ���� ��ȣ == �⵵ ù���� => 1900�� 1�� == ������ == 1
		// ���� ��ȣ == �ش� �� ù ���� 
		int day =  ((leap * 2 + common + 1) + (dateSum - date)) % 7;

		printf("===================== %d�� %d�� =======================\n", year, month);
		// UI - ���� %4s�� ����, ���� %4s�� �ٸ����� ���� ���� => ������� ������, �ٹٲ��� �Է� 
		printf("%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s\n", "��", " ", "��", " ", "ȭ", " ", "��", " ", "��", " ", "��", " ", "��");
		print(day, date);
	}

	
	
	
	
	
	return 0;
}
