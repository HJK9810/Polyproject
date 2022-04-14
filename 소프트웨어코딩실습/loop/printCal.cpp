#include <stdio.h>

int calcul(int year, int month) {
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
	int day =  (yearSum + dateSum + 1) % 7; // ���� ��� = 1������ 7�� => 0 = ��, 1 = ��.... 
	
	return date * 10 + day;
}

void printUI(int year, int month, int days) { 
	int today = 1; // for ��¥
	int date = days / 10; // ��� - day : ����, date : ��������¥ 
	int day = days % 10;
	
	printf("===================== %d�� %d�� =======================\n", year, month);
	// UI - ���� %4s�� ����, ���� %4s�� �ٸ����� ���� ���� => ������� ������, �ٹٲ��� �Է� 
	printf("%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s\n", "��", " ", "��", " ", "ȭ", " ", "��", " ", "��", " ", "��", " ", "��");
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
		printf("  �⵵ �Է�(1900��� ���ĸ� �����մϴ�. 0�� �����Դϴ�.) : ");
		scanf("%d", &year);
		
		if(year == 0) break; // �⵵�� 0�ϰ��, ���ѷ��� ���� 
		else if(year < 1900) continue; // ���� �̳��ϰ��, ���Է� 
		
		printf("  �� �Է�(1 ~ 12���̸� �Է� �����մϴ�.) : ");
		scanf("%d", &month);
		
		if (month < 1 || month > 13) continue; // ���� �̳��ϰ��, ���Է� 
		
		printf("\n\n");	
		
		int days =  calcul(year, month); // days = �������� * 10 + ����(0~6) 
		printUI(year, month, days); // ����� ���� �Լ� 
	}

	return 0;
}
