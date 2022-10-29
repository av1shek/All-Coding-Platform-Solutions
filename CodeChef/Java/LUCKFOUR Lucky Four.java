import java.util.Scanner;
import java.lang.Math;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for(int i = 0; i < t; i++) {
			 Integer n = sc.nextInt();
			 
			 String num = n.toString();
			 int sum = 0;
			 for(int j = 0; j < num.length(); j++) {
				 if(num.charAt(j) == '4') sum++;
			 }
			 System.out.println(sum);
		}
	}
}
