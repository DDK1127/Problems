// LeetCode 72. Edit Distance

class Solution {
public:
    int minDistance(string word1, string word2) {
        int s1 = word1.size(), s2 = word2.size();
        vector<vector<int> > vv(s1+1, vector<int>(s2+1, 0));
        for(int i = 0; i <= s1; i++)
            vv[i][0] = i;
        for(int i = 0; i <= s2; i++)
            vv[0][i] = i;
        // string start with 1.
        for(int i = 1; i <= s1; i++){
            for(int j = 1; j <= s2; j++){
                if(word1[i-1] == word2[j-1])
                    vv[i][j] = vv[i-1][j-1];
                else
                    vv[i][j] = min(min(vv[i-1][j], vv[i][j-1]), vv[i-1][j-1])+1;
            }
        }
        return vv[s1][s2];
    }
};