import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return int整型
     */
    private boolean isDigit(char c){
        return '0' <= c && c <= '9';
    }
    public int StrToInt (String s) {
        int n = s.length();
        int idx = 0;
        while(idx < n){
            if(s.charAt(idx) == ' '){
                ++idx;
            } else break;
        }
        if(idx == n) return 0;
        int sign = 1;
        if(s.charAt(idx) == '-') {
            sign = -1;
            ++idx;
        } else if(s.charAt(idx) == '+'){
            ++idx;
        }
        else if(!isDigit(s.charAt(idx))) return 0;
        long res = 0;
        int len = 0;
        while(idx < n){
            if(!isDigit(s.charAt(idx))){
                break;
            }
            res = res*10 + s.charAt(idx++)-'0';
            if(res > 0 && ++len == 11) {  // 000000012345678
                if(sign == 1) return Integer.MAX_VALUE;
                return Integer.MIN_VALUE;
            }
        }
        res *= sign;
        if(res > Integer.MAX_VALUE) return Integer.MAX_VALUE;
        if(res < Integer.MIN_VALUE) return Integer.MIN_VALUE;
        return (int)res;
    }
}