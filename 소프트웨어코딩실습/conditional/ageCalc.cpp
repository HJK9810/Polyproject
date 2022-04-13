#include <stdio.h>
#include <time.h>

int main() {
	int yourAge = 0; // 입력용 변수 
	
	time_t t = time(NULL); // 오늘날짜 
	struct tm tm = *localtime(&t);
	int nyear = tm.tm_year + 1900; // 년도 - 1900년부터 올해까지의 누적년도 
	int nmonth = tm.tm_mon + 1; // 월  - 0~11 
	int nday = tm.tm_mday;
	
	printf("주민번호 앞자리 입력 : ");
	scanf("%d", &yourAge);
	int yyear = yourAge / 10000; // 주민번호 = 년도뒤의 두자리 + 월 두자리 + 날짜 두자리 
	int ymonth = yourAge % 10000 / 100;
	int yday = yourAge % 100;
	
	if(nyear % 100 < yyear) yyear += 1900; // 올해 년도 뒤의 두자리보다 크다? 1900년대생 
	else yyear += 2000; // 작거나 같다? 2000년대생 
	
	int age = nyear - yyear; // 양쪽 모두  
	int kage = age; // 한국나이 
	
	if(nmonth < ymonth) age -= 1; // 생일이 지나지 않았을경우 
	else if(nmonth == ymonth && nday >= yday) age -=1;	// 해당 달임에도 날짜가 아직 지나지 않았을경우 
	
	printf("오늘(%d년 %d월 %d일)기준 나이는 %d세, 만 나이는 %d세 입니다.", nyear, nmonth, nday, kage, age);
	return 0;
}
