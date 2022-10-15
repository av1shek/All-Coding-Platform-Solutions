import java.util.*;

public class anyBaseAddition {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int b = scn.nextInt();
        int n1 = scn.nextInt();
        int n2 = scn.nextInt();

        int d = getSum(b, n1, n2);
        System.out.println(d);
    }

    public static int getSum(int b, int n1, int n2) {
        // write ur code here
        int res = 0, carry = 0, multiplier = 1;
        // multiplier is for adding the numbers to the power of 10.
        // Eg: 256 = 2*10^2 + 5*10^1 + 6*1

        while (n1 > 0 || n2 > 0 || carry > 0) {
            int d1 = n1 % 10;
            int d2 = n2 % 10;
            int sum = d1 + d2 + carry;
            int ad_val = sum % b;

            res = res + (ad_val * multiplier);

            carry = sum / b;
            multiplier *= 10;
            n1 /= 10;
            n2 /= 10;
        }

        return res;
    }
}