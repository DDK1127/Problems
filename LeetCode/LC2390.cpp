// LeetCode 2390.Removing Stars From a String

class Solution {
public:
    string removeStars(string s) {
        stack<char> ss;
        string result = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '*')
                ss.push(s[i]);
            else
                ss.pop();
        }
        while(!ss.empty()){
            result += ss.top();
            ss.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }   
};