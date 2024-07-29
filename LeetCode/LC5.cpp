// LeetCode 5. Longest Palindromic Substring
// Expand Around Center

class Solution {
public:
    int MMMax = 0, location;
    string longestPalindrome(string s) {
        if(s.size() == 1)
            return s;
        string result = "";
        for(int i = 0; i < s.size(); i++){
            search(s, i, i+1);
            search(s, i, i+2);
        }
        for(int i = 0; i < MMMax; i++)
            result += s[location--];
        return result;
    }
    void search(string s, int l, int r){
        int max;
        if(r == l+1)
            max = 0;
        else
            max = 1;
        while(l >= 0 && r < s.size() && s[l] == s[r])
            l--, r++, max+=2;
        if(MMMax < max)
            MMMax = max, location = r-1;
    }
};