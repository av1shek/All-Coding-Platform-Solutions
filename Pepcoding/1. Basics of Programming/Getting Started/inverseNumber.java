import java.util.*;

public class inverseNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int num = sc.nextInt();
        int count = 0, revNum = 0;

        while (num != 0) {
            count++;
            int r = num % 10;
            revNum += count * Math.pow(10, r - 1);
            num /= 10;
        }
        System.out.println(revNum);
    }
}
