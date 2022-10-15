import java.io.*;
import java.util.*;

public class subsetsOfArray {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int arr[] = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int limit = (int) Math.pow(2, arr.length);

        for (int i = 0; i < limit; i++) {
            int temp = i;
            String val = "";
            for (int j = arr.length - 1; j >= 0; j--) {
                int r = temp % 2;
                temp /= 2;

                if (r == 0) {
                    val = "-\t" + val;
                } else {
                    val = arr[j] + "\t" + val;
                }
            }
            System.out.println(val);
        }
    }

}