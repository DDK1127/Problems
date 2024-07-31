// LeetCode 2414. Length of the Longest Alphabetical Continuous Substring

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int max = 1, res = 1;
        for(int i = 0; i < s.size()-1; i++){
            if(s[i]+1 == s[i+1])
                max++;
            else
                max = 1;
            if(max > res)
                res = max;
        }
        return res;
    }
};