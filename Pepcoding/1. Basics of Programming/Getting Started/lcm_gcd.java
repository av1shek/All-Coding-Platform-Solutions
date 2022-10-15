import java.util.*;

public class lcm_gcd {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int num1 = sc.nextInt();
        int num2 = sc.nextInt();

        int a = Math.max(num1, num2);
        int b = Math.min(num1, num2);

        int r = b;

        while (a % b != 0) {
            r = a % b;
            a = b;
            b = r;
        }

        int lcm = (num1 * num2) / r;

        System.out.println("GCD is : " + r);
        System.out.println("LCM is : " + lcm);
    }
}
