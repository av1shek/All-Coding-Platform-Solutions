import java.io.*;
import java.util.*;

public class rotateAnArray {
    public static void display(int[] a) {
        StringBuilder sb = new StringBuilder();

        for (int val : a) {
            sb.append(val + " ");
        }
        System.out.println(sb);
    }

    // helper function to rotate array elements to the right by one
    public static void rotateByOne(int[] a) {
        int last = a[a.length - 1];
        for (int i = a.length - 2; i >= 0; i--) {
            a[i + 1] = a[i];
        }
        a[0] = last;
    }

    public static void rotate(int[] a, int k) {
        // write your code here
        int n = a.length;

        k = k % n;
        if (k < 0) {
            k = k + n;
        }

        for (int i = 0; i < k; i++) {
            rotateByOne(a);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(br.readLine());
        }
        int k = Integer.parseInt(br.readLine());

        rotate(a, k);
        display(a);
    }

}