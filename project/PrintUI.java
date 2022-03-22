package project;

import java.util.ArrayList;
import java.util.Scanner;

public class PrintUI {
	protected String printMonth() {
		Scanner scanner = new Scanner(System.in);
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
		Scanner scanner = new Scanner(System.in);
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
}