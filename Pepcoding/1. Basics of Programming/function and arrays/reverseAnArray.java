import java.io.*;
import java.util.*;

public class reverseAnArray {
    public static void display(int[] a) {
        StringBuilder sb = new StringBuilder();

        for (int val : a) {
            sb.append(val + " ");
        }
        System.out.println(sb);
    }

    // code with temp array and extra space
    // public static void reverse(int[] a) {
    // // write your code here
    // int n = a.length;
    // int arr[] = new int[n];
    // int j = n - 1;
    // for (int i = 0; i < arr.length; i++) {
    // arr[i] = a[j--];
    // }

    // display(arr);
    // }

    // code with single array, and no extra space
    public static void reverse(int[] a) {
        // write your code here
        for (int i = 0; i < a.length / 2; i++) {
            int temp = a[i];
            a[i] = a[a.length - 1 - i];
            a[a.length - 1 - i] = temp;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(br.readLine());
        }

        reverse(a);

        // code with single array
        display(a);
    }

}