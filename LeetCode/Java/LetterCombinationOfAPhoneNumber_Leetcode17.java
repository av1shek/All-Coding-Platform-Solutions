import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

class LetterCombinationsOfAPhoneNumber_LeetCode17 {
    public List<String> letterCombinations(String digits) {
 HashMap<String,String> h=new HashMap<>();
        h.put("2","abc");
        h.put("3","def");
        h.put("4","ghi");
        h.put("5","jkl");
        h.put("6","mno");
        h.put("7","pqrs");
        h.put("8","tuv");
        h.put("9","wxyz");
        List<String> s=new ArrayList<>();
        if(digits.length()==0)
        return s;
        find(digits,s,h,"");
        return s;
        
    }
    static void find(String s,List<String> l,HashMap<String,String> h,String temp)
    {
        if(s.length()==0)
        {
            l.add(temp);
            //temp=temp.substring(1);
            return ;
        }
        int n=s.length();
        //int end=n-1;
        String id=h.get(s.substring(n-1));//String corresponding to Individual Digits
        for(int i=0;i<id.length();i++)
        {
            //temp=id.charAt(i)+temp;
            find(s.substring(0, n-1),l,h,id.substring(i,i+1)+temp);
            //temp=temp.substring(1);
        }

    }}