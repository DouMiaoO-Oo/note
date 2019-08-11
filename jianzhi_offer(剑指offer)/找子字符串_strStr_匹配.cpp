#include <iostream>
#include <string>
#include <vector>
using namespace std;

int strStr(string s, string p){
    /*
        input:
            s: string
            p: pattern
        output:
            -1 for not found pattern p in s
            otherwise, the index of p first appear in s
    */
    int i = 0, j = 0;
    while(i < s.length() && j < p.length()){
        if(s[i] == p[j]) {
            ++i;
            ++j;
        } else{
          i = i-j+1;  // 回到这一趟比较时，i的下一个位置,容易弄错
          j = 0;
        }
    } if(j == p.length()) return i-j;  // 这里的return容易弄错
    return -1;
}


vector<int> get_next(string p){
    /*
        通过模式串构造next数组
        kmp算法调整时参考的next数组取决于模式串而不是主串
    */
    if(p.size() == 0) return vector<int>();
    vector<int> next(p.length());  // next的长度等于模式串长度
    int i = 0, j = -1;
	next[i] = j; // next[1] = 0;  // 也可以直接初始化
    while (i+1 < p.length()){  // 递推next[i+1]
		// assert (j = next[i])
        if(j == -1 || p[i] == p[j]){
            next[++i] = ++j;
        } else j = next[j];
    } return next;
}
int KMP(string s, string p, int pos=0){
    /*
        input:
            s: string
            p: pattern
            pos: find pattern start with s[pos]
        output:
            -1 for not found pattern p in s
            otherwise, the index of p first appear in s started in pos
    */
    if(!(0 <= pos && pos < s.length())){
        cout << "pos must be in the [0, s.length)" << endl;
        return -1;
    }
    vector<int> next = get_next(p);
    //cout << "next: "; for (int i = 0; i < next.size(); ++i) cout << next[i]+1 << ' '; cout << endl;
    int i = pos, j = 0;
    int step = 0;
    while((i < s.length()) && (j < int(p.length()))){
        if(j == -1 || (s[i] == p[j])) {
            cout << "step=" << step++ << ' ';
            cout << "match. s[" << i << "]=p[" << j << "]" << endl;
            ++i;
            ++j;
        }
        else{
          cout << "step=" << step++ << ' ';
          cout << "not match. current j=" << j << ",";
          cout << "new_j=next[j]=next[" << j << "]=" << next[j] << endl;
          j = next[j];
        }
    }
    cout << "step=" << step++ << '\n';
    if(j == p.length()) return i-j;
    return -1;
}

int main(){
    //vector<int> res = get_next("abaabcac");
    //for (int i = 0; i < res.size(); ++i) cout << res[i]+1 << endl;
    //cout << strStr("ababcabcacbab", "abcac") << endl;
    //cout << KMP("ababcabcacbab", "abcac") << endl;
    cout << "result of finding pattern: " << KMP("abcabaaabaabcac", "abaabcac") << endl;
    cout << "result of finding pattern: " << KMP("", "") << endl;
    cout << "result of finding pattern: " << KMP("mississippi", "issipi") << endl;
    cout << "result of finding pattern: " << KMP("mississippi", "issip") << endl;


    //cout << "result of finding pattern: " << strStr("", "") << endl;

    return 0;
}
