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
//		String homeTown = fp.homeTown;

		if (town != "all") {
			String key = town;
			String[] ary = list.get(key);
			int leng = ary.length;
			if (leng > 5) leng = 5;

			System.out.println(town + "에서의 유동인구 top5와 worst5");
			System.out.println("Max\t\tMin");
			for (int i = 1; i < leng + 1; i++) {
				String[] maxarr = ary[i].split("-");
				String[] minarr = ary[ary.length - i].split("-");
				System.out.println(maxarr[0] + ":" + maxarr[1] + "\t" + minarr[0] + ":" + minarr[1]);
			}
		}
	}
}