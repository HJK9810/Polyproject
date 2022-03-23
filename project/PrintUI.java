package project;

import java.util.ArrayList;
import java.util.Scanner;

public class PrintUI {
	Scanner scanner = new Scanner(System.in);

	protected String printMonth() {
		String month = "";

		while (true) {
			System.out.println("Whitch month do you want to check?");
			int num = scanner.nextInt();

			if (num < 10 && num > 0) {
				month = "0" + num;
				break;
			} else if (num < 13) {
				month = num + "";
				break;
			} else System.out.println("Out of order. One more to push another month.");
		}

		return month;
	}

	protected String printTowns() {
		ArrayList<String> fullTowns1 = new ArrayList<>();
		ArrayList<String> fullTowns2 = new ArrayList<>();

		ArrayList<String> count1 = new ArrayList<>();
		ArrayList<String> count2 = new ArrayList<>();
		String[] ary1 = { "서울", "부산", "대구", "인천", "광주", "대전", "울산", "세종" };
		String[] ary2 = { "경기도", "강원도", "충청북도", "충청남도", "전라북도", "전라남도", "경상북도", "경상남도", "제주" };

		for (int i = 0; i < ary1.length; i++) {
			fullTowns1.add(ary1[i] + "\t");
			count1.add(i + "\t");
		}
		for (int i = 0; i < ary1.length; i++) {
			fullTowns2.add(ary2[i] + "\t");
			count2.add(i + "\t");
		}

		int num = 0;
		while (true) {
			System.out.println("원하는 출발지를 선택하세요.");
			System.out.println("1. 특별자치시\n2. 도");
			num = scanner.nextInt();
			if (num == 1) {
				System.out.println(fullTowns1);
				System.out.println(count1);

				System.out.println("원하는 행정구역의 번호를 선택하세요.(해당 번호는 아래 위치한 번호입니다.)");
				return ary1[scanner.nextInt()];
			} else if (num == 2) {
				System.out.println(fullTowns2);
				System.out.println(count2);

				System.out.println("원하는 행정구역의 번호를 선택하세요.(해당 번호는 아래 위치한 번호입니다.)");
				return ary2[scanner.nextInt()];
			} else {
				System.out.println("Out of order. Error. chose one more!");
			}
		}
	}

	protected String printGAndY() {
		while (true) {
			System.out.print("성별을 입력하세요(M - 남성 / W - 여성) : ");
			String gender = scanner.next().toUpperCase();

			if (gender.equals("W")) {
				System.out.print("나이를 입력하세요 : ");
				int num = scanner.nextInt();
				if(num / 10 < 1) continue;
				return (num / 10) + "0대여성";
			} else if (gender.equals("M")) {
				System.out.print("나이를 입력하세요 : ");
				int num = scanner.nextInt();
				if(num / 10 < 1) continue;
				return (num / 10) + "0대남성";
			} else System.out.println("다시 입력하세요.");
		}
	}
	
	protected String printsortedTowns() {
		floatpop fp = new floatpop();
		ArrayList<String> towns = fp.maintowns;
		
		while(true) {
			System.out.println("이하의 행정구역중 원하는 시군의 번호를 선택하세요.(전체를 원할경우 0을 선택하세요.)");
			System.out.println(towns);
			System.out.print("[0\t, ");
			for(int i = 1; i < towns.size() - 1; i++) {
				System.out.print(i + "   , ");
			}
			System.out.println((towns.size() - 1) + "\t]");
			
			int num = scanner.nextInt();
			if(num == 0) return "all";
			else if (num < towns.size()) return towns.get(num);
			else System.out.println("해당하지 않습니다. 범위내의 수를 입력해주세요.");
		}
	}
}