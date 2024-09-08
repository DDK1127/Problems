// LeetCode 1071.Greatest Common Divisor of strings

class Solution {
public:
    int gcd(int a,int b){
        if(a % b == 0)
            return b;
        else
            return gcd(b, a%b);
    }
    string gcdOfStrings(string str1, string str2) {
        int g = gcd(str1.size(), str2.size());
        bool correct = true;
        string s = "";
        for(int i = 0; i < min(str1.size(), str2.size()); i++){
            if(str1[i] != str2[i]){
                correct = false;
                break;
            }
        }
        if(str1+str2 != str2+str1)
            correct = false;
        if(correct){
            for(int i = 0; i < g; i++)
                s += str1[i];
            return s;
        }else
            return "";
    }
};