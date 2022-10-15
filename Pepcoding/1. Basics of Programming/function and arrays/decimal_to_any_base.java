import java.util.*;

public class decimal_to_any_base {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int b = scn.nextInt();
        int dn = getValueInBase(n, b);
        System.out.println(dn);
    }

    public static int getValueInBase(int n, int b) {
        // write code here
        int num = 0, count = 0;
        while (n != 0) {
            int r = n % b;
            int ad_val = r * (int) (Math.pow(10, count));
            num = ad_val + num;
            count++;
            n = n / b;
        }
        return num;
    }
}