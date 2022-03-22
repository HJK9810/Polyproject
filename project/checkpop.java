package project;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class checkpop {

	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(System.in);
		floatpop fp = new floatpop();
		PrintUI ui = new PrintUI();

		fp.ReWritecsv();
		System.out.println();
		try {
			BufferedReader br = new BufferedReader(new FileReader("C:\\javatest\\시군유동인구.txt"));
			String line;
			
			while((line = br.readLine()) != null) {
				System.out.println(line);
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}