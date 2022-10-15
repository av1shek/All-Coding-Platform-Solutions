import java.io.*;
import java.util.*;

public class sumOfTwoArrays {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n1 = sc.nextInt();
        int arr1[] = new int[n1];

        for (int i = 0; i < arr1.length; i++) {
            arr1[i] = sc.nextInt();
        }

        int n2 = sc.nextInt();
        int arr2[] = new int[n2];

        for (int i = 0; i < arr2.length; i++) {
            arr2[i] = sc.nextInt();
        }

        int max = Math.max(n1, n2);
        int ans_arr[] = new int[max];

        int carry = 0;
        int i = n1 - 1;
        int j = n2 - 1;
        int k = max - 1;

        while (k >= 0) {
            int digit = carry;
            if (i >= 0) {
                digit += arr1[i--];
            }

            if (j >= 0) {
                digit += arr2[j--];
            }

            carry = digit / 10;
            ans_arr[k--] = digit % 10;
        }

        if (carry > 0) {
            System.out.println(carry);
        }
        for (int k2 = 0; k2 < ans_arr.length; k2++) {
            System.out.println(ans_arr[k2]);
        }
    }

}