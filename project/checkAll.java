package project;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

public class checkAll {
	public void printAll() {
		floatpop fp = new floatpop();
		checkAll cA = new checkAll();
		String path = fp.path;
		
		HashMap<String, Float> towns = new HashMap<>();
		
		try {
			BufferedReader br = new BufferedReader(new FileReader(path));
			String line;
			while((line = br.readLine())!=null) {
				String[] ary = line.split(",");
				if(ary[0].equals("년월")) continue;
				
				String str = ary[1] + "-" + ary[2];
				towns.put(str, Float.parseFloat(ary[3]));
				
				if(towns.size() > 10) {
					towns = cA.compare(towns);
				}
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		System.out.println("Worst");
		for(Entry<String, Float> town :towns.entrySet()) {
			String[] arr = town.getKey().split("-");
			System.out.println(arr[0]+"에서 " + arr[1]+":"+arr[2]);
		}
	}
	
	protected HashMap<String, Float> compare(HashMap<String, Float> map) {
		List<Map.Entry<String, Float>> entries = new ArrayList<>(map.entrySet());
		entries.sort(Map.Entry.comparingByValue()); // hashmap sort
		ArrayList<String> changeList = new ArrayList<>(); // set arraylist
		
		for (Map.Entry<String, Float> entry : entries) { // input key and value to string
			changeList.add(entry.getKey() + "=" + entry.getValue());
		}
		
		map = new HashMap<>();
		for(int i = 0;i<10;i++) {
			String[] ary = changeList.get(i).split("=");
			map.put(ary[0], Float.parseFloat(ary[1]));
		}		
		
		return map;
	}
}