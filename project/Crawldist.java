package project;

import java.util.ArrayList;

import org.openqa.selenium.By;
import org.openqa.selenium.Keys;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.chrome.ChromeOptions;

public class Crawldist {
	private String town;

	public Crawldist(String town) {
		this.town = town;
	}
	
	public void checkdistance() {
		checkpop cp = new checkpop();
		checkAll ca = new checkAll();
		Crawldist cd = new Crawldist(town);
		
		String DRIVER_ID = "webdriver.chrome.driver";
		String DRIVER_PATH = "C:\\Crawling\\chromedriver.exe";

		System.setProperty(DRIVER_ID, DRIVER_PATH);
		ChromeOptions chromeOptions = new ChromeOptions();
		chromeOptions.addArguments("--headless");
		chromeOptions.addArguments("--no-sandbox");
		WebDriver driver = new ChromeDriver(chromeOptions);

		try {
			driver.get("https://www.google.co.kr/");
			
			ArrayList<String> top = null;
			ArrayList<String> worst = null;
			
			if(!town.equals("all")) {
				top = cp.top5;
				worst = cp.worst5;
			} else {
				top = ca.top10;
				worst = ca.worst10;
			}
			
			System.out.println("\nPrint tops' distances list");
			cd.findDistance(top, town, driver);

			System.out.println("\nPrint worsts' distances list");
			cd.findDistance(worst, town, driver);
			
			driver.quit();

		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	protected void findDistance(ArrayList<String> list, String town, WebDriver driver) {
		driver.get("https://www.google.co.kr/");
		
		for (String search : list) {
			
			WebElement web1 = driver
					.findElement(By.xpath("/html/body/div[1]/div[3]/form/div[1]/div[1]/div[1]/div/div[2]/input"));
			web1.sendKeys(search);
			try {
				Thread.sleep(200);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}

			web1.sendKeys(Keys.ENTER);

			try {
				Thread.sleep(300);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			// bring distance text
			String distance = driver.findElement(By.xpath("/html/body/div[7]/div/div[10]/div/div[2]/div[2]/div/div/div[1]/div/div/div[1]/div/div[1]")).getText();
			System.out.println(search + " : " + distance);
			
			driver.findElement(By.xpath("/html/body/div[4]/div[2]/form/div[1]/div[1]/div[1]/a/img")).click();
		}
	}
}