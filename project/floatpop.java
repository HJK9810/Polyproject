package project;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class floatpop {

	public static void ReWritecsv() throws IOException {
		FileWriter fw = new FileWriter("C:\\javatest\\시군유동인구.txt", false);
		try {
			BufferedReader br = new BufferedReader(new FileReader("C:\\javatest\\시군별유동인구데이터.csv"));
			String line;

			while ((line = br.readLine()) != null) {
				// date, incode, in, outcode, out, man 10~70, woman 10~70
				String[] ary = line.split(",");
				if (ary.length < 5 || ary[0].replace(" ", "").length() < 6) {
					fw.write(line);
					continue;
				}
				String month = ary[0].replace(" ", "").substring(4);

				if (!ary[1].equals(ary[3])) {
					String str = month + "," + ary[2] + "," + ary[4];
					for (int i = 5; i < ary.length; i++) {
						long num = Math.round(Double.parseDouble(ary[i]));
						str += ("," + num);
					}

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
