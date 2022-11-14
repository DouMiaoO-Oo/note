/*
```mermaid
graph TD;
0--空格-->0;
0--+/- --->1;
0--\d--->2;
2--\d--->2;
2--dot--->3;
3--\d--->4;
4--\d--->4;
1--\d--->2;
1--dot--->5;
5--\d--->6;
6--\d--->6;
2--e/E--->7;
3--e/E--->7;
4--e/E--->7;
6--e/E--->7;
7--+/- --->8;
7-- \d --->9;
8-- \d --->9;
9-- \d --->9;

2((2))--空格-->10;
3((3))--空格-->10;
4((4))--空格-->10;
6((6))--空格-->10;
9((9))--空格-->10;
10((10))--空格-->10;
```
* */
public class Solution {
     private static boolean isDigit(char c){
        return '0' <= c && c <= '9';
    }
    private static boolean isSign(char c){
        return c == '+' || c == '-';
    }
    private static final int SPACE = 0;
    private static final int SIGN = 1;
    private static final int DIGIT = 2;
    private static final int DOT = 3;
    private static final int E = 4;
    private static final int [][] TRANSITION_TABLE = new int[11][];
    static {
        TRANSITION_TABLE[0] = new int[]{0, 1, 2, 5, -1};
        TRANSITION_TABLE[1] = new int[]{-1, -1, 2, 5, -1};
        TRANSITION_TABLE[2] = new int[]{10, -1, 2, 3, 7};
        TRANSITION_TABLE[3] = new int[]{10, -1, 4, -1, 7};
        TRANSITION_TABLE[4] = new int[]{10, -1, 4, -1, 7};
        TRANSITION_TABLE[5] = new int[]{-1, -1, 6, -1, -1};
        TRANSITION_TABLE[6] = new int[]{10, -1, 6, -1, 7};
        TRANSITION_TABLE[7] = new int[]{-1, 8, 9, -1, -1};
        TRANSITION_TABLE[8] = new int[]{-1, -1, 9, -1, -1};
        TRANSITION_TABLE[9] = new int[]{10, -1, 9, -1, -1};
        TRANSITION_TABLE[10] = new int[]{10, -1, -1, -1, -1};
    }
    public boolean isNumeric (String str) {
        char [] carr = (str+" ").toCharArray();  // add a sentinel space
        if(carr.length == 0) return false;
        int action;
        int state = 0;
        for(char c: carr){
            if(c == ' ') action = SPACE;
            else if(isSign(c)) action = SIGN;
            else if(isDigit(c)) action = DIGIT;
            else if(c == '.') action = DOT;
            else if(c == 'e' || c == 'E') action = E;
            else return false;
            state = TRANSITION_TABLE[state][action];
            if(state == -1) return false;
        }
        return state == 10;
    }
}
