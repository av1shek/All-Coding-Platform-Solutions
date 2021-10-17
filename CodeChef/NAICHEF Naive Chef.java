import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt(), n;
		int[] arr, ab = new int[2];
		double numA, numB;
		
		for(int i = 0; i < t; i++) {
			n = sc.nextInt();
			arr = new int[n];
			ab[0] = sc.nextInt();
			ab[1] = sc.nextInt();
			numA = numB = 0;
			
			for(int j = 0; j < n; j++) {
				arr[j] = sc.nextInt();
				if(arr[j] == ab[0]) numA++;
				if(arr[j] == ab[1]) numB++;
			}
			
			double res = (double) ((numA/n) * (numB/n));
			System.out.println(res);
		}
	}
}
