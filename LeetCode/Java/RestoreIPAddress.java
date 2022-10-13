import java.util.ArrayList;
import java.util.List;

class RestoreIpAddress {
    public List<String> restoreIpAddresses(String s) {
        List<String> result = new ArrayList<>();
        if(s.length() < 4)
            return result;
        find(s, 0, new StringBuilder(""), 0, result);
        return result;
    }
    
    public void find(String s, int index, StringBuilder curr, int nd, List<String> result){
        if(index < s.length() && nd > 3){	
            return;
        }
        if(index == s.length() && nd == 4){
            curr.setLength(curr.length()-1);
            result.add(curr.toString());
            return;
        }

        for(int i=index+1;i<=s.length();i++){
            if(i-index > 3){
                break;
            }
            String str= s.substring(index, i);
            if(str.length() > 1 && str.charAt(0) == '0') {
                break;
            }
            if(str.length() <= 3 && Integer.valueOf(str) <= 255 & nd <4) {
                int len = curr.length();
                curr = curr.append(str).append(".");
                find(s,i,curr,nd+1,result); 
                curr.setLength(len);
            }
        }

    }
}