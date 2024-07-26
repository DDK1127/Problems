// LeetCode 1768. Merge Strings Alternately

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i, n = min(word1.size(), word2.size());
        string result = "";
        for(i = 0; i < n; i++){
            result += word1[i];
            result += word2[i];
        }
        while(word1.size() > i)
            result += word1[i++]; 
        while(word2.size() > i)
            result += word2[i++]; 
        return result;
    }
};