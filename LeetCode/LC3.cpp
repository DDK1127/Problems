// LeetCode 3.Longest Substring Without Repeating Characters

class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        int i = 0;
        vector<int> v(128, -1); // ASCII table use to match.
        int result = 0;

        for(int  j = 0; j < s.size(); j++){
            // cout << "\nround => " << j+1 << endl;
            if(v[s[j]] != -1)
                i = max(i, v[s[j]]+1);
            result = max(result , j-i+1);
            v[s[j]] = j;
            // cout << "j = " << j << ", i = " << i << endl;
            // cout << "v[s] = " << v[s[j]] << endl;
        }
        return result;
    }
};