package project;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class checkAll {
	protected ArrayList<String> top10 = new ArrayList<>();
	protected ArrayList<String> worst10 = new ArrayList<>();

	public void printAll() {
		Scanner scanner = new Scanner(System.in);
		floatpop fp = new floatpop();
		checkAll cA = new checkAll();

		HashMap<String, Float> towns = fp.Alltowns;

		ArrayList<String> townlist = cA.compare(towns);

		System.out.println("If print worst, do you want to delet 0.0?(Yes input > 0, No input <= 0)");
		int num = scanner.nextInt();
		System.out.println("\n전체에서의 유동인구");
		System.out.println("Top 10");
		for (int i = 0; i < 10; i++) {
			int listsize = townlist.size() - 1;
			String[] ary = townlist.get(listsize - i).split("-");
			System.out.println((i + 1) + ". \'" + ary[0] + "\' 에서 \'" + ary[1] + "\' : " + ary[2]);
			cA.top10.add(ary[0] + "에서 " + ary[1] + " 거리");
		}

		System.out.println("\nWorts 10");
		if (num <= 0) {
			for (int i = 0; i < 10; i++) {
				String[] ary = townlist.get(i).split("-");
				System.out.println((i + 1) + ". \'" + ary[0] + "\' 에서 \'" + ary[1] + "\' : " + ary[2]);
			}
		} else {
			int j = 0;
			ArrayList<String> zeros = new ArrayList<>();
			for (int i = 0; i < 10 + j; i++) {
				String[] ary = townlist.get(i + j).split("-");
				if (ary[2].equals("0.0")) {
					zeros.add("\'" + ary[0] + "\' 에서 \'" + ary[1] + "\'");
					j++;
				} else {
					if (i == townlist.size() - 1) break;
					System.out.println((i + 1 - j) + ". \'" + ary[0] + "\' 에서 \'" + ary[1] + "\' : " + ary[2]);
					cA.worst10.add(ary[0] + "에서 " + ary[1] + " 거리");
				}
			}
			System.out.println("\nThey are \"0.0\" cities : " + zeros.size());
			for (String str : zeros) {
				System.out.println(str);
			}
		}
	}

	protected ArrayList<String> compare(HashMap<String, Float> map) {
		List<Map.Entry<String, Float>> entries = new ArrayList<>(map.entrySet());
		entries.sort(Map.Entry.comparingByValue()); // hashmap sort
		ArrayList<String> changeList = new ArrayList<>(); // set arraylist

		for (Map.Entry<String, Float> entry : entries) { // input key and value to string
			changeList.add(entry.getKey() + "-" + entry.getValue());
		}

		return changeList;
	}
}