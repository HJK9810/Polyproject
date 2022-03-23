package project;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class checkAll {
	public void printAll() {
		floatpop fp = new floatpop();
		checkAll cA = new checkAll();
		String path = fp.path;

		HashMap<String, Float> towns = new HashMap<>();

		try {
			BufferedReader br = new BufferedReader(new FileReader(path));
			String line;
			while ((line = br.readLine()) != null) {
				String[] ary = line.split(",");
				if (ary[0].equals("년월"))
					continue;

				String str = ary[1] + "-" + ary[2];
				towns.put(str, Float.parseFloat(ary[3]));
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		ArrayList<String> townlist = cA.compare(towns);

		System.out.println("전체에서의 유동인구");
		System.out.println("Top 10");
		for (int i = 0; i < 10; i++) {
			int listsize = townlist.size() - 1;
			String[] ary = townlist.get(listsize - i).split("-");
			System.out.println((i + 1) + ". " + ary[0] + " 에서 " + ary[1] + ":" + ary[2]);
		}

		System.out.println("Worts 10");
		for (int i = 0; i < 10; i++) {
			String[] ary = townlist.get(i).split("-");
			System.out.println((i + 1) + ". " + ary[0] + " 에서 " + ary[1] + ":" + ary[2]);
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