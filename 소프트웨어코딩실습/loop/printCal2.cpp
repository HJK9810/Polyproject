#include <stdio.h>

void print(int day, int date) { // ��� - day : ����, date : ��������¥ 
	int today = 1; // for ��¥

	for(int idx = 0; idx < 5; idx++) { // �Ѵ� == 5�� ��� 
		for(int jdx = 0; jdx < 7; jdx++) { // 1���� ��� 
			if(idx == 0 && jdx < day) printf("\t");
			else { // \t == %8s == %8d 
				printf("%4d%4s", today, " ");
				today++; // ��¥ �߰� 
			}
			
			if(today > date) { // ���� ���ڸ� ��� ��������� 
				idx++; // ����, �ش� ���� ��°�ֿ� ��������� -> idx�� 5�� ����� for�� Ż�� 
				break; // ���� for�� ���� 
			}
		}
		printf("\n"); // �ش� �ְ� �����⿡ �ٹٲ� 
	}
	
	printf("\n\n"); // �޷���� �Ϸ���, ���� �� �޷��� ���� ��ĭ���� 2�� 
}

int main() {
	int year = 1900; // ��ǻ�� �⺻ �⵵ 
	int month = 1;	// ��ǻ�� �⺻ �� 
	
	while(true) { // ���ѷ��� 
		int dates[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // idx = �� �� => �������, 1�� ���� ��¥�� 
		printf("  �⵵ �Է�(1900��� ���ĸ� �����մϴ�. 0�� �����Դϴ�.) : ");
		scanf("%d", &year);
		
		if(year == 0) break; // �⵵�� 0�ϰ��, ���ѷ��� ���� 
		else if(year < 1900) continue; // ���� �̳��ϰ��, ���Է� 
		
		printf("  �� �Է�(1 ~ 12���̸� �Է� �����մϴ�.) : ");
		scanf("%d", &month);
		
		if (month < 1 || month > 13) continue; // ���� �̳��ϰ��, ���Է� 
		
		printf("\n\n");	
		
		int count = year - 1900; // 1900��� ���ĸ� ������ ��� 
		int yearSum = 0; // �Է� ���⵵���� ���� �� ��¥�� �� 
		
		for(int idx = 0; idx < count; idx++) { 
			int checkY = 1900 + idx; // ������ �˾ƺ��� ���� ���� 
			
			// ������ ���� : 4�� ������� 100�� ����� �ƴҶ� or 400�� ����϶�
			// ���� = 1�� 366��, ��� = 1�� 365�� 
			if (checkY % 4 == 0 && checkY % 100 != 0) yearSum += 366;
			else if(checkY % 400 == 0) yearSum += 366;
			else {
				yearSum += 365;
				dates[2] = 28; // �迭 �ʱ�ȭ�� ��������̱⿡ 
			}
		}
		
		int dateSum = 0;
		for(int idx = 1; idx < month; idx++) {
			dateSum += dates[idx];
		}
		
		// yearsum = 1900���� �������� �Է� �⵵���� �c ������ �������� ��� 
		// dateSum = 1���� �������� �Է� �� ���� �� ������ �������� ��� 
		int day =  (yearSum + dateSum + 1) % 7; // ���� ��� = 1������ 7�� => 0 = ��, 1 = ��.... 

		printf("===================== %d�� %d�� =======================\n", year, month);
		// UI - ���� %4s�� ����, ���� %4s�� �ٸ����� ���� ���� => ������� ������, �ٹٲ��� �Է� 
		printf("%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s\n", "��", " ", "��", " ", "ȭ", " ", "��", " ", "��", " ", "��", " ", "��");
		print(day, dates[month]); // ����� ���� �Լ� - ����, �ش�� �������� 
	}

	return 0;
}
