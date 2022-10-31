class Solution {
    public int numDecodings(String s) {
    int sing=0;
    int dou=0;
    if(s.charAt(0)!='0'){
        sing=1;
    }  
    for(int i =1;i<s.length();i++){
        int s2=sing+dou;
        if(s.charAt(i)=='0'){
            s2=0;
        }
        
        int d2=sing;
        if(Integer.valueOf(s.substring(i-1,i+1))>26){
            d2=0;
        }
        sing=s2;
        dou=d2;
    } 
    return sing+dou;
    }
}