/**
 * Problem Link- https://leetcode.com/problems/wiggle-subsequence/
 * Problem Description- 
 * A wiggle sequence is a sequence where the differences between 
 * successive numbers strictly alternate between positive and negative. 
 * The first difference (if one exists) may be either positive or negative. 
 * A sequence with one element and a sequence with two non-equal elements are trivially 
 * wiggle sequences.
 */
class WiggleSequence_Problem376 {
    public int wiggleMaxLength(int[] numbers) {
        if(numbers.length<2)
            return numbers.length;
        int [] upArr=new int [numbers.length];
        int [] downArr=new int[numbers.length];
        upArr[0]=downArr[0]=1;
        for(int i=1;i<numbers.length;i++)
        {
            if(numbers[i]>numbers[i-1])
            {
                upArr[i]=downArr[i-1]+1;
                downArr[i]=downArr[i-1];
            }
            else
                if(numbers[i]<numbers[i-1])
                {
                    downArr[i]=upArr[i-1]+1;
                    upArr[i]=upArr[i-1];
                }
            else
            {
                downArr[i]=downArr[i-1];
                upArr[i]=upArr[i-1];
            }
        }
        return Math.max(downArr[numbers.length-1],upArr[numbers.length-1]);
    }
}