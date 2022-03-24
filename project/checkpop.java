package project;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

public class checkpop {
	protected ArrayList<String> top5 = new ArrayList<>();
	protected ArrayList<String> worst5 = new ArrayList<>();

	public static void main(String[] args) throws IOException {
		floatpop fp = new floatpop();
		PrintUI pui = new PrintUI();
		checkpop cp = new checkpop();

		fp.ReWritecsv();
		System.out.println();
		String town = pui.printsortedTowns();

		HashMap<String, String[]> list = fp.list;

		if (town != "all") {
			String key = town;
			String[] ary = list.get(key);
			int leng = ary.length;
			if (leng > 5) leng = 5;

			System.out.println(town + "에서의 유동인구 top5와 worst5");
			System.out.println("Top\t\t\t\tworst");

			for (int i = 0; i < leng + 1; i++) {
				String[] maxarr = ary[ary.length - 1 - i].split("-");
				String[] minarr = ary[i].split("-");
				System.out.println((i + 1) + ". " + maxarr[0] + " : " + maxarr[1] + "\t " + (i + 1) + ". " + minarr[0] + " : " + minarr[1]);
				
				cp.top5.add(maxarr[0] + "-" + maxarr[1]);
				cp.worst5.add(minarr[0] + "-" + minarr[1]);
			}
		} else {
			checkAll cA = new checkAll();
			cA.printAll();
		}
		
		pui.printdistance(town);
	}
}