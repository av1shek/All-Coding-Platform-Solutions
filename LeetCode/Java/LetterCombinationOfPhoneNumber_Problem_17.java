/**
 * 17. Letter Combinations of a Phone Number
 * Problem Link- https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 * Problem Description-
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
 * A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 */

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class LetterCombinationOfPhoneNumber_Problem_17 {
    static HashMap<Character,List<Character>> hm=new HashMap<>();
    static List<String> ans=new ArrayList<>();
    static List<String> letterCombinations(String s)
    {
        ans.clear();
        if(s.length()==0)
        {
            return ans;
        }
        List<Character> ls2=new ArrayList<>();
        ls2.add('a');
        ls2.add('b');
        ls2.add('c');
        hm.put('2',ls2);

        List<Character> ls3=new ArrayList<>();
        ls3.add('d');
        ls3.add('e');
        ls3.add('f');
        hm.put('3',ls3);

        List<Character> ls4=new ArrayList<>();
        ls4.add('g');
        ls4.add('h');
        ls4.add('i');
        hm.put('4',ls4);

        List<Character> ls5=new ArrayList<>();
        ls5.add('j');
        ls5.add('k');
        ls5.add('l');
        hm.put('5',ls5);

        List<Character> ls6=new ArrayList<>();
        ls6.add('m');
        ls6.add('n');
        ls6.add('o');
        hm.put('6',ls6);

        List<Character> ls7=new ArrayList<>();
        ls7.add('p');
        ls7.add('q');
        ls7.add('r');
        ls7.add('s');
        hm.put('7',ls7);

        List<Character> ls8=new ArrayList<>();
        ls8.add('t');
        ls8.add('u');
        ls8.add('v');
        hm.put('8',ls8);

        List<Character> ls9=new ArrayList<>();
        ls9.add('w');
        ls9.add('x');
        ls9.add('y');
        ls9.add('z');
        hm.put('9',ls9);

        String temp="";
        find(s,0,temp);
        return ans;
    }
    static void find(String s,int x,String temp)
    {
        if(x==s.length())
        {
            ans.add(temp);
            return;
        }
        char c=s.charAt(x);
        for(int i=0;i<hm.get(c).size();i++)
        {
           //temp+=hm.get(c).get(i);
           find(s,x+1,temp+hm.get(c).get(i));
           //temp=temp.substring(0,x);
        }
    }
    
}