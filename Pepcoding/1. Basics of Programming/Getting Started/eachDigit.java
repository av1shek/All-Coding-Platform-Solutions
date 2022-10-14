// Problem : Digits of a number

import java.util.*;

public class eachDigit {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int num = sc.nextInt();

        // prints each individual digit in reverse order
        // while (num != 0) {
        // int r = num % 10;
        // System.out.println(r);
        // num /= 10;
        // }

        // prints each individual digit in correct order
        String str = Integer.toString(num);
        for (int i = 0; i < str.length(); i++) {
            System.out.println(str.charAt(i));
        }

    }
}
