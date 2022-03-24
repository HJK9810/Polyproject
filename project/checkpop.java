package project;

import java.io.IOException;

public class checkpop {
	public static void main(String[] args) {
		floatpop fp = new floatpop();
		PrintUI pui = new PrintUI();

		try { // for write csv and separate
			fp.ReWritecsv();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println();
		String town = pui.printsortedTowns();
		
		PrintSeperTown pst = new PrintSeperTown(town);
		pst.printTown(); // print top and worst list

		pui.printdistance(town); // for print distance
	}
}