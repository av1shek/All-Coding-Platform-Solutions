import java.util.*;

public class any_base_to_decimal {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int b = scn.nextInt();
        int d = getValueIndecimal(n, b);
        System.out.println(d);
    }

    public static int getValueIndecimal(int n, int b) {
        // write your code here
        int num = 0, count = 0;

        while (n != 0) {
            int r = n % 10;
            int ad_val = r * (int) Math.pow(b, count);
            num += ad_val;

            n = n / 10;
            count++;
        }

        return num;
    }
}