package project;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
import java.util.Map.Entry;

public class floatpop {
	protected static HashMap<String, String[]> list = new HashMap<>();
	protected static ArrayList<String> maintowns = new ArrayList<>();
	protected static String homeTown = "";

	public static void ReWritecsv() throws IOException {
		PrintUI pui = new PrintUI();
		String month = pui.printMonth();
		String towns = pui.printTowns();
		String yandg = pui.printGAndY();
		FileWriter fw = new FileWriter("C:\\javatest\\" + month + "월" + towns + "시군유동인구.txt", false);

		try {
			BufferedReader br = new BufferedReader(new FileReader("C:\\javatest\\시군별유동인구데이터.csv"));
			String line;
			int idx = -1;

			HashMap<String, Float> sorted = new HashMap<>();

			String start = "";

			while ((line = br.readLine()) != null) {
				// date, incode, in, outcode, out, man 10~70, woman 10~70
				String[] ary = line.split(",");

				if (ary[0].equals("년월")) {
					for (int i = 0; i < ary.length; i++) {
						if (ary[i].contains(yandg)) {
							idx = i;
							break;
						}
					}
					start = ary[2];
					fw.write(ary[0] + "," + ary[2] + "," + ary[4] + ", " + yandg + "\n");
					continue;
				}
				if (ary.length < 5 || ary[0].replace(" ", "").length() < 6) continue;
				if (!month.equals(ary[0].replace(" ", "").substring(4))) continue;

				if (!ary[1].equals(ary[3]) && ary[2].contains(towns)) {
					if (ary[2].equals(start)) {
						sorted.put(ary[4], Float.parseFloat(ary[idx]));
					} else {
						List<Map.Entry<String, Float>> entries = new ArrayList<>(sorted.entrySet());
						entries.sort(Map.Entry.comparingByValue());
						ArrayList<String> changeList = new ArrayList<>();
						
						for(Map.Entry<String, Float> entry : entries) {
							changeList.add(entry.getKey() + "-" + entry.getValue());
						}
						String[] arr = changeList.toArray(new String[changeList.size()]);
						
						
						String[] tstart = start.split(" ");
						
						if(tstart.length == 1) {
							list.put(start, arr);
							maintowns.add(start);
						} else {
							homeTown = tstart[0];
							list.put(tstart[1], arr);
							maintowns.add(tstart[1]);
						}
						start = ary[2];
					}

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
}
