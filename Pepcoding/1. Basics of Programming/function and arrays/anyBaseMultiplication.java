import java.util.*;

public class anyBaseMultiplication {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int b = scn.nextInt();
        int n1 = scn.nextInt();
        int n2 = scn.nextInt();

        int d = getProduct(b, n1, n2);
        System.out.println(d);
    }

    // actual function to get product between two numbers : n1 % n2
    public static int getProduct(int b, int n1, int n2) {
        int result = 0, multiplier = 1;
        while (n2 > 0) {
            int d2 = n2 % 10;
            n2 /= 10;

            int singleProduct = getSingleProduct(b, n1, d2);
            singleProduct *= multiplier;

            result = getSum(b, result, singleProduct);
            multiplier *= 10;
        }
        return result;
    }

    // function to product of n1 and each digit of n2
    public static int getSingleProduct(int b, int n1, int d2) {
        int result = 0, carry = 0, multiplier = 1;
        while (n1 > 0 || carry > 0) {
            int d1 = n1 % 10;
            n1 /= 10;

            int prod = (d1 * d2) + carry;
            carry = prod / b;
            int mul_val = prod % b;

            result = result + (mul_val * multiplier);
            multiplier *= 10;
        }
        return result;
    }

    // function to get sum of each row of multiplication results.
    public static int getSum(int b, int n1, int n2) {
        int result = 0, carry = 0, multiplier = 1;
        while (n1 > 0 || n2 > 0 || carry != 0) {
            int d1 = n1 % 10;
            n1 /= 10;
            int d2 = n2 % 10;
            n2 /= 10;

            int sum = d1 + d2 + carry;
            carry = sum / b;
            int ad_val = sum % b;

            result += ad_val * multiplier;

            multiplier *= 10;
        }
        return result;
    }

}