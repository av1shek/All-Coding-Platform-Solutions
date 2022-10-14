import java.util.*;
import java.io.*;

public class brokenEconomy {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int arr[] = new int[n];

        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextInt();
        }

        int d = sc.nextInt();

        int low = 0;
        int high = arr.length - 1;

        int ceil = 0, floor = 0;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] == d) {
                ceil = floor = arr[mid];
                break;
            } else if (d < arr[mid]) {
                high = mid - 1;
                ceil = arr[high];
            } else {
                low = mid + 1;
                floor = arr[low];
            }
        }

        System.out.println(arr[low]);
        System.out.print(arr[high]);

    }
}
