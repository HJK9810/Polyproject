package project;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

public class checkpop {
	protected static ArrayList<String> top5 = new ArrayList<>();
	protected static ArrayList<String> worst5 = new ArrayList<>();

	public static void main(String[] args) throws IOException {
		floatpop fp = new floatpop();
		PrintUI pui = new PrintUI();
		checkpop cp = new checkpop();

		fp.ReWritecsv();
		System.out.println();
		String town = pui.printsortedTowns();
		String bigtown = fp.towns;

		HashMap<String, String[]> list = fp.list;

		if (!town.equals("all")) {
			String key = town;
			String[] ary = list.get(key);
			int leng = ary.length;
			if (leng > 5) leng = 5;

			System.out.println(town + "에서의 유동인구 top5와 worst5");
			System.out.println("Top\t\t\t\tworst");

			for (int i = 0; i < leng; i++) {
				String[] maxarr = ary[ary.length - 1 - i].split("-");
				String[] minarr = ary[i].split("-");
				System.out.println((i + 1) + ". " + maxarr[0] + " : " + maxarr[1] + "\t " + (i + 1) + ". " + minarr[0] + " : " + minarr[1]);

				top5.add(bigtown + " " + town + "에서 " + maxarr[0] + " 거리");
				worst5.add(bigtown + " " + town + "에서 " + minarr[0] + " 거리");
			}
		} else {
			checkAll cA = new checkAll();
			cA.printAll();
		}

		pui.printdistance(town);
	}
}