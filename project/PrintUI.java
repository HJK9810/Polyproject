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
		String[] ary1 = { "����", "�λ�", "�뱸", "��õ", "����", "����", "���", "����" };
		String[] ary2 = { "��⵵", "������", "��û�ϵ�", "��û����", "����ϵ�", "���󳲵�", "���ϵ�", "��󳲵�", "����" };

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
			System.out.println("���ϴ� ������� �����ϼ���.");
			System.out.println("1. Ư����ġ��\n2. ��");
			num = scanner.nextInt();
			if (num == 1) {
				System.out.println(fullTowns1);
				System.out.println(count1);

				System.out.println("���ϴ� ���������� ��ȣ�� �����ϼ���.(�ش� ��ȣ�� �Ʒ� ��ġ�� ��ȣ�Դϴ�.)");
				return ary1[scanner.nextInt()];
			} else if (num == 2) {
				System.out.println(fullTowns2);
				System.out.println(count2);

				System.out.println("���ϴ� ���������� ��ȣ�� �����ϼ���.(�ش� ��ȣ�� �Ʒ� ��ġ�� ��ȣ�Դϴ�.)");
				return ary2[scanner.nextInt()];
			} else {
				System.out.println("Out of order. Error. chose one more!");
			}
		}
	}

	protected String printGAndY() {
		while (true) {
			System.out.print("������ �Է��ϼ���(M - ���� / W - ����) : ");
			String gender = scanner.next().toUpperCase();

			if (gender.equals("W")) {
				System.out.print("���̸� �Է��ϼ��� : ");
				int num = scanner.nextInt();
				if(num / 10 < 1) continue;
				return (num / 10) + "0�뿩��";
			} else if (gender.equals("M")) {
				System.out.print("���̸� �Է��ϼ��� : ");
				int num = scanner.nextInt();
				if(num / 10 < 1) continue;
				return (num / 10) + "0�볲��";
			} else System.out.println("�ٽ� �Է��ϼ���.");
		}
	}
	
	protected String printsortedTowns() {
		floatpop fp = new floatpop();
		ArrayList<String> towns = fp.maintowns;
		
		while(true) {
			System.out.println("������ ���������� ���ϴ� �ñ��� ��ȣ�� �����ϼ���.(��ü�� ���Ұ�� 0�� �����ϼ���.)");
			System.out.println(towns);
			System.out.print("[0\t, ");
			for(int i = 1; i < towns.size() - 1; i++) {
				System.out.print(i + "   , ");
			}
			System.out.println((towns.size() - 1) + "\t]");
			
			int num = scanner.nextInt();
			if(num == 0) return "all";
			else if (num < towns.size()) return towns.get(num);
			else System.out.println("�ش����� �ʽ��ϴ�. �������� ���� �Է����ּ���.");
		}
	}
}