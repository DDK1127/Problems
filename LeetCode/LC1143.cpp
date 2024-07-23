// LeetCode 1143. Longest Common Subsequence
// Time Complexity = O(MN) (M, N = string length
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int i, j, r = text1.size(), c = text2.size();
        vector<vector<int> > vv(r+1, vector<int> (c+1, 0));
            for(i = 0; i < r; i++){
                for(j = 0; j < c; j++){
                    if(text1[i] == text2[j])
                        vv[i+1][j+1] = vv[i][j]+1;
                    else
                        vv[i+1][j+1] = max(vv[i+1][j], vv[i][j+1]);
                }
            }
        return vv[i][j];
    }
};