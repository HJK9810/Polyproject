package project;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class floatpop {

	public static void ReWritecsv() throws IOException {
		FileWriter fw = new FileWriter("C:\\javatest\\�ñ������α�.txt", false);
		PrintUI pui = new PrintUI();
		String month = pui.printMonth();
		String towns = pui.printTowns();
		String yandg = pui.printGAndY();
		
		try {
			BufferedReader br = new BufferedReader(new FileReader("C:\\javatest\\�ñ��������α�������.csv"));
			String line;
			int idx = -1;

			while ((line = br.readLine()) != null) {
				// date, incode, in, outcode, out, man 10~70, woman 10~70
				String[] ary = line.split(",");
				
				if (ary[0].equals("���")) {
					for(int i=0;i<ary.length;i++) {
						if(ary[i].contains(yandg)) {
							idx = i;
							break;
						}
					}
					fw.write(ary[0] + "," + ary[2] + "," + ary[4] + ", " + yandg + "\n");
					continue;
				}
				if (ary.length < 5 || ary[0].replace(" ", "").length() < 6) continue;
				if (!month.equals(ary[0].replace(" ", "").substring(4))) continue;

				if (!ary[1].equals(ary[3]) && ary[2].contains(towns)) {
					String str = month + "��," + ary[2] + "," + ary[4] + ", " + ary[idx];

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
