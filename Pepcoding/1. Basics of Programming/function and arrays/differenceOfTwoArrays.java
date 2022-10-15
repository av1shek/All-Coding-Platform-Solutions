import java.io.*;
import java.util.*;

public class differenceOfTwoArrays {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner sc = new Scanner(System.in);

        int n1 = sc.nextInt();
        int num1[] = new int[n1];
        for (int i = 0; i < num1.length; i++) {
            num1[i] = sc.nextInt();
        }

        int n2 = sc.nextInt();
        int num2[] = new int[n2];
        for (int i = 0; i < num2.length; i++) {
            num2[i] = sc.nextInt();
        }

        int ans_arr[] = new int[n2];

        int i = n1 - 1;
        int j = n2 - 1;
        int k = n2 - 1;

        int carry = 0;
        while (k >= 0) {

            int digit = 0;
            int num1v = i >= 0 ? num1[i] : 0;

            if (num2[j] + carry >= num1v) {
                digit = (num2[j] + carry) - num1v;
                carry = 0;
            } else {
                digit = (num2[j] + carry + 10) - num1v;
                carry = -1;
            }

            ans_arr[k--] = digit;
            i--;
            j--;
        }

        int k2 = 0;
        while (k2 < ans_arr.length) {
            if (ans_arr[k2] == 0) {
                k2++;
            } else {
                break;
            }
        }

        for (int k3 = k2; k3 < ans_arr.length; k3++) {
            System.out.println(ans_arr[k3]);
        }

    }

}