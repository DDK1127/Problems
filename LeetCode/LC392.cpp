// LeetCode 392.Is Subsequence

class Solution {
public:
    bool isSubsequence(string s, string t){
        int ss = s.size(), st = t.size(), pt = 0, n = 0;
        while(pt < st){
            if(s[n] == t[pt++])
                n++;
        }
        return n == ss ? true:false;
    }
}