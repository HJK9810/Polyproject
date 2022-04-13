#include <stdio.h>

void print(int day, int date) { // ��� 
	int line = 0; // ����üũ�� ���� �������� 
	
	for(int idx = 1; idx < date + 1; idx++) { // 1���� �����ϸ� ������ ��¥���� ��� 
		if(idx == 1 && line < day) { // �ش� ������ ù ���ϰ� �������� ������ 
			printf("\t"); // ����� ��ĭ. \t == %8s 
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
		printf("  �⵵ �Է�(1900��� ���ĸ� �����մϴ�. 0�� �����Դϴ�.) : ");
		scanf("%d", &year);
		
		if(year == 0) break; // �⵵�� 0�ϰ��, ���ѷ��� ���� 
		else if(year < 1900) continue; // ���� �̳��ϰ��, ���Է� 
		
		printf("  �� �Է�(1 ~ 12���̸� �Է� �����մϴ�.) : ");
		scanf("%d", &month);
		
		if (month < 1 || month > 13) continue; // ���� �̳��ϰ��, ���Է� 
		
		printf("\n\n");	
		
		int count = year - 1900; // 1900��� ���ĸ� ������ ��� 
		int yearSum = 0; 
		
		for(int idx = 0; idx < count; idx++) { 
			int checkY = 1900 + idx; // ������ �˾ƺ��� ���� ���� 
			
			// ������ ���� : 4�� ������� 100�� ����� �ƴҶ� or 400�� ����϶�
			// ���� = 1�� 366��, ��� = 1�� 365�� 
			if (checkY % 4 == 0 && checkY % 100 != 0) yearSum += 366;
			else if(checkY % 400 == 0) yearSum += 366;
			else yearSum += 365;
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
			// �Է��� ���� ������ �������� �����ʿ� ���� 
			if(idx != month) dateSum += date;		
		}
		
		// yearsum = 1900���� �������� �Է� �⵵���� �c ������ �������� ��� 
		// dateSum = 1���� �������� �Է� �� ���� �� ������ �������� ��� 
		int day =  (yearSum + dateSum) % 7; // ���� ��� = 1������ 7�� => 0 = ��, 1 = ��.... 

		printf("===================== %d�� %d�� =======================\n", year, month);
		// UI - ���� %4s�� ����, ���� %4s�� �ٸ����� ���� ���� => ������� ������, �ٹٲ��� �Է� 
		printf("%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s\n", "��", " ", "��", " ", "ȭ", " ", "��", " ", "��", " ", "��", " ", "��");
		print(day, date); // ����� ���� �Լ� 
	}

	return 0;
}
