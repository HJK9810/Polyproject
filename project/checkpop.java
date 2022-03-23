package project;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class checkpop {

	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(System.in);
		floatpop fp = new floatpop();
		PrintUI pui = new PrintUI();

		fp.ReWritecsv();
		System.out.println();
		String town = pui.printsortedTowns();

		ArrayList<String> maintowns = fp.maintowns;
		HashMap<String, String[]> list = fp.list;

		if (town != "all") {
			String key = town;
			String[] ary = list.get(key);
			int leng = ary.length;
			if (leng > 5) leng = 5;

			System.out.println(town + "에서의 유동인구 top5와 worst5");
			System.out.println("Top\t\t\t\tworst");

			for (int i = 0; i < leng + 1; i++) { // if min == 0.0?
				String[] maxarr = ary[ary.length - 1 - i].split("-");
				String[] minarr = ary[i].split("-");
				if(maxarr[0].length() > minarr[0].length()) {
					System.out.println(maxarr[0] + ":" + maxarr[1] + "\t " + minarr[0] + ":" + minarr[1]);
				} else {
					System.out.println(maxarr[0] + ":" + maxarr[1] + "\t\t " + minarr[0] + ":" + minarr[1]);
				}
			}
		}
	}
}