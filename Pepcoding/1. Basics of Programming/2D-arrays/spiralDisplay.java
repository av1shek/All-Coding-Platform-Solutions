import java.io.*;
import java.util.*;

public class spiralDisplay {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        int arr[][] = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = sc.nextInt();
            }
        }

        System.out.println("---------------------------------------");

        int k = 0, l = 0, count = 0, total = m * n;

        while (k < n && l < m) {

            if (count == total) {
                break;
            }

            for (int i = k; i < n; i++) {
                System.out.println(arr[i][l]);
                count++;
            }
            l++;

            if (count == total) {
                break;
            }

            for (int i = l; i < m; i++) {
                System.out.println(arr[n - 1][i]);
                count++;
            }
            n--;

            if (count == total) {
                break;
            }

            if (k < n) {
                for (int i = n - 1; i >= k; i--) {
                    System.out.println(arr[i][m - 1]);
                    count++;
                }
                m--;
            }

            if (count == total) {
                break;
            }

            if (l < m) {
                for (int i = m - 1; i >= l; i--) {
                    System.out.println(arr[k][i]);
                    count++;
                }
                k++;
            }

        }
    }
}
