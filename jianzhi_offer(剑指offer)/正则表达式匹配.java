public class Solution {
    private boolean helper(String str, int x, String pat, int y){
        if(x == str.length() && y == pat.length()) return true;
        if(x < str.length() && y == pat.length()) return false;
         if(x == str.length() && y < pat.length()){
//              if(pat.charAt(y) == '*') return helper(str, x, pat,y+1);
             if(y+1 < pat.length() && pat.charAt(y+1) == '*')
                return helper(str, x, pat,y+2);
             return false;
         }
        if(y+1 < pat.length() && pat.charAt(y+1) == '*'){
            if(str.charAt(x) == pat.charAt(y) || pat.charAt(y) == '.')
                return helper(str, x+1, pat,y+2)
                    || helper(str, x+1, pat,y)
                    || helper(str, x, pat,y+2);
//             if(str.charAt(x) != pat.charAt(y)) 
                return helper(str, x, pat,y+2);
        }
        // 此时下一个不是*
        if(pat.charAt(y) == '.' || str.charAt(x) == pat.charAt(y)) return helper(str,x+1,pat,y+1);
        return false;
    }
    public boolean match (String str, String pat) {
        return helper(str,0,pat,0);
    }
}
