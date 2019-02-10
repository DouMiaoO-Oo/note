#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <sstream>
#include <cmath>
#include <unordered_set>  // 需要c++ 11才能支持
#include <unordered_map>  // 需要c++ 11才能支持
using namespace std;
class ToString {
public:
    string toString(int x) {
        // assert x >= 0
        if(x == 0) return digits[0];
        int id = 0; // id for bigs
        string str = "";
        while(x > 0){
            if(x%1000 > 0){
                string prefix = num2str100(x%1000);
                if(id != 0){
                    prefix += " " + bigs[id];
                }
                if(str != "") prefix += ",";
                str = prefix + str;
            } x /= 1000;
            ++id;
        } return str;
    }
private:
    static const string digits[11], teens[10], tens[10], bigs[3];
    string num2str100(int x){
        // assert 0 < x < 1000
        string str = "";
        if(x > 100){
            str += digits[x/100] + " Hundred";
        }
        int teen = (x/10)%10;
        if(teen == 1){
            if(str != "") str += " ";
            if(x%10 == 0){
                str += digits[10];
            } else{
                str += teens[x%10];
            }
        } else{ // 0 or 2+ for teen
            string s = tens[teen]; // 0 for ""
            int digit = x%10;
            if(digit != 0){
                if(s != "") s += " ";
                s += digits[digit];
            }
            if(s != ""){
                if(str != "") str += " ";
                str += s;
            }
        } return str;
    }
};
const string ToString::digits[11] = {"Zero", "One", "Two", "Three", "Four", "Five",
    "Six", "Seven", "Eight", "Nine", "Ten"},
ToString::teens[10] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                       "Sixteen", "Seventeen", "Eighteen", "Nineteen"},
ToString::tens[10] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty",
                    "Sixty", "Seventy", "Eighty", "Ninety"},
ToString::bigs[3] = {"", "Thousand", "Million"};

int main(){
    cout << ToString().toString(1234) << "|" << endl;
    return 0;
}
