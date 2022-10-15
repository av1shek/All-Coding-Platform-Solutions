import java.util.*;

public class anyBase_to_anyBase {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int sourceBase = scn.nextInt();
        int destBase = scn.nextInt();

        int dec_val = covertDecimal(n, sourceBase);
        int final_val = convertAnyBase(dec_val, destBase);

        System.out.println(final_val);
    }

    public static int covertDecimal(int n, int sourceBase) {

        if (sourceBase == 10) {
            return n;
        }

        int num = 0, count = 0;

        while (n != 0) {
            int r = n % 10;
            int add_val = r * (int) (Math.pow(sourceBase, count));
            num += add_val;

            n /= 10;
            count++;
        }

        return num;
    }

    public static int convertAnyBase(int dec_val, int destBase) {
        int num = 0, count = 0;

        while (dec_val != 0) {
            int r = dec_val % destBase;
            int ad_val = r * (int) (Math.pow(10, count));
            num += ad_val;

            dec_val /= destBase;
            count++;
        }
        return num;
    }

}