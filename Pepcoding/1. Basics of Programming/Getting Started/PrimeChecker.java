// java program to check if a number is prime or not
public class PrimeChecker {
    public static void main(String[] args) {
        int num = 31;

        boolean isPrime = true;
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
            System.out.println(num + " is prime.");
        else
            System.out.println(num + " is not prime");
    }
}
