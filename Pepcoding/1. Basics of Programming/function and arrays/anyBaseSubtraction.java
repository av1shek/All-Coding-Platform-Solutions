import java.util.*;

public class anyBaseSubtraction {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int b = scn.nextInt();
        int n1 = scn.nextInt();
        int n2 = scn.nextInt();

        int d = getDifference(b, n1, n2);
        System.out.println(d);
    }

    public static int getDifference(int b, int n1, int n2) {
        // write your code here
        int result = 0, carry = 0, multiplier = 1;

        while (n2 > 0) {
            int d1 = n1 % 10;
            n1 /= 10;

            int d2 = n2 % 10;
            n2 /= 10;
            d2 += carry;

            int d = 0;
            if (d2 >= d1) {
                carry = 0;
                d = d2 - d1;
            } else {
                carry = -1;
                d = d2 + b - d1;
            }

            result = result + (d * multiplier);
            multiplier *= 10;
        }
        return result;
    }

}