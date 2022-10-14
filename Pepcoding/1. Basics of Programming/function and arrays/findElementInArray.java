import java.io.*;
import java.util.*;

public class findElementInArray {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] arr = new int[n];

        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextInt();
        }

        int key = sc.nextInt();

        int flag = 1;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == key) {
                flag = i;
                break;
            }
            flag = -1;
        }

        System.out.print(flag);
    }

}