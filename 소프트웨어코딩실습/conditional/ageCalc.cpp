#include <stdio.h>
#include <time.h>

int main() {
	int yourAge = 0; // �Է¿� ���� 
	
	time_t t = time(NULL); // ���ó�¥ 
	struct tm tm = *localtime(&t);
	int nyear = tm.tm_year + 1900; // �⵵ - 1900����� ���ر����� �����⵵ 
	int nmonth = tm.tm_mon + 1; // ��  - 0~11 
	int nday = tm.tm_mday;
	
	printf("�ֹι�ȣ ���ڸ� �Է� : ");
	scanf("%d", &yourAge);
	int yyear = yourAge / 10000; // �ֹι�ȣ = �⵵���� ���ڸ� + �� ���ڸ� + ��¥ ���ڸ� 
	int ymonth = yourAge % 10000 / 100;
	int yday = yourAge % 100;
	
	if(nyear % 100 < yyear) yyear += 1900; // ���� �⵵ ���� ���ڸ����� ũ��? 1900���� 
	else yyear += 2000; // �۰ų� ����? 2000���� 
	
	int age = nyear - yyear; // ���� ���  
	int kage = age; // �ѱ����� 
	
	if(nmonth < ymonth) age -= 1; // ������ ������ �ʾ������ 
	else if(nmonth == ymonth && nday >= yday) age -=1;	// �ش� ���ӿ��� ��¥�� ���� ������ �ʾ������ 
	
	printf("����(%d�� %d�� %d��)���� ���̴� %d��, �� ���̴� %d�� �Դϴ�.", nyear, nmonth, nday, kage, age);
	return 0;
}
