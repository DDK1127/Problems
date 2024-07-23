// LeetCode 516. Longest Palindromic Subsequence
// Time Complexity : O(n^2)
// 2 way

class Solution {
public:
    int longestPalindromeSubseq(string s) {

        int i, j, n = s.size();
        vector<vector<int> > v(n+1, vector<int>(n+1, 0));

        for(i = n-1; i >= 0; i--){
            for(j = i-1; j < n; j++){
                if(i == j)
                    v[i+1][j+1] = 1;
                else if(i < j){
                    if(s[i] == s[j])
                        v[i+1][j+1] = v[i+2][j]+2;
                    else
                        v[i+1][j+1] = max(v[i+2][j+1], v[i+1][j]);
                }
                else{}
            }
        }
        // string ss = s;
        // int i, j, n = s.size();
        // reverse(s.begin(), s.end());
        // vector<vector<int> > v(n+1, vector<int>(n+1, 0));

        // for(i = 0; i < n; i++){
        //     for(j = 0; j < n; j++){
        //         if(ss[i] == s[j])
        //             v[i+1][j+1] = v[i][j]+1;
        //         else
        //             v[i+1][j+1] = max(v[i+1][j], v[i][j+1]);
        //     }
        // }
        return v[1][n];
    }
};