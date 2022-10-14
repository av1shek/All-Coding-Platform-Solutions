import java.util.*;

public class trial {

    public static void main(String[] args) {

        int nums[] = new int[] { -100, -98, -1, 2, 3, 4 };

        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + "\t");
        }
        System.out.println();

        Arrays.sort(nums);

        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + "\t");
        }
        System.out.println();

        int len = nums.length;

        int fProd = -1;
        if (nums[0] < 0 && nums[1] < 0) {
            fProd = nums[0] * nums[1] * nums[len - 1];
        }

        int lProd = nums[len - 1] * nums[len - 2] * nums[len - 3];

        int maxProd = Math.max(fProd, lProd);

        System.out.println(maxProd);

    }
}