import java.io.*;
import java.util.*;

public class firstIndex_lastIndex {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int d = sc.nextInt();

        int first = 0, last = arr.length - 1;
        boolean found1 = false, found2 = false;

        for (int i = 0; i < arr.length; i++) {
            if (found1 == false) {
                if (arr[first] == d) {
                    found1 = true;
                } else {
                    first++;
                }
            }
            if (found2 == false) {
                if (arr[last] == d) {
                    found2 = true;
                } else {
                    last--;
                }
            }
        }

        if (found2 && found1) {
            System.out.println(first);
            System.out.print(last);
        } else {
            System.out.println(-1);
            System.out.print(-1);
        }

    }

}