package project;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class floatpop {
	protected static HashMap<String, String[]> list = new HashMap<>();
	protected static ArrayList<String> maintowns = new ArrayList<>();
	protected static String path = "";
	protected static HashMap<String, Float> Alltowns = new HashMap<>();

	public void ReWritecsv() throws IOException {
		PrintUI pui = new PrintUI();
		floatpop fp = new floatpop();
		String month = pui.printMonth();
		String towns = pui.printTowns();
		String yandg = pui.printGAndY();
		// for rewrite
		path = "C:\\javatest\\유동인구\\" + month + "월" + towns + "시군" + yandg + "대유동인구.csv";
		FileWriter fw = new FileWriter(path, false);

		try {
			BufferedReader br = new BufferedReader(new FileReader("C:\\javatest\\시군별유동인구데이터.csv"));
			String line;
			int idx = -1;

			HashMap<String, Float> sorted = new HashMap<>(); // string for in & float for people

			String start = ""; // where to arrive

			while ((line = br.readLine()) != null) {
				// date, incode, in, outcode, out, man 10~70, woman 10~70
				String[] ary = line.split(",");

				if (ary[0].equals("년월")) { // the first line
					for (int i = 0; i < ary.length; i++) {
						if (ary[i].contains(yandg)) { // check index which want to check age
							idx = i;
							break;
						}
					}
					start = ary[2]; // set where to arrive
					fw.write(ary[0] + "," + ary[2] + "," + ary[4] + ", " + yandg + "\n");
					continue;
				}
				if (ary.length < 5 || ary[0].replace(" ", "").length() < 6) continue;
				if (!month.equals(ary[0].replace(" ", "").substring(4))) continue;

				// check which want to from big cities && not same town to same town
				if (ary[2].contains(towns) && !ary[1].equals(ary[3])) {
					if (ary[2].equals(start)) {
						sorted.put(ary[4], Float.parseFloat(ary[idx]));
					} else {
						String[] arr = fp.mapsorted(sorted);

						String[] tstart = start.split(" ");

						if (tstart.length == 1) { // for the first line
							list.put(start, arr);
							maintowns.add(start);
						} else {
							if(!list.containsKey(tstart[1])) maintowns.add(tstart[1]);
							list.put(tstart[1], arr);
						}
						
						start = ary[2];
						tstart = start.split(" ");
						
						if(tstart.length != 1 && list.containsKey(tstart[1])) { // if same towns?
							String[] array = list.get(tstart[1]);
							sorted = new HashMap<>();
							
							for (String str : array) {
								String[] formap = str.split("-");
								sorted.put(formap[0].trim(), Float.parseFloat(formap[1].trim()));
							}
						} else {
							sorted = new HashMap<>();
						}

						sorted.put(ary[4], Float.parseFloat(ary[idx]));
					}
					
					Alltowns.put(ary[2] + "-" + ary[4], Float.parseFloat(ary[idx]));
					String str = month + "월," + ary[2] + "," + ary[4] + ", " + ary[idx];
					fw.write(str + "\n");
				}
			}
			fw.close();

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	protected String[] mapsorted(HashMap<String, Float> map) {
		List<Map.Entry<String, Float>> entries = new ArrayList<>(map.entrySet());
		entries.sort(Map.Entry.comparingByValue()); // hashmap sort
		ArrayList<String> changeList = new ArrayList<>(); // set arraylist for change array

		for (Map.Entry<String, Float> entry : entries) { // input key and value to string
			changeList.add(entry.getKey() + "-" + entry.getValue());
		}
		String[] ary = changeList.toArray(new String[changeList.size()]); // arraylist to array

		return ary;
	}
}
