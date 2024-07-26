// LeetCode 151. Reverse Words in a String

class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string str = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' ')
                str += s[i];
            if(s[i] == ' ' && str != ""){
                v.push_back(str);
                str = "";
            };
        }
        if(str != "")
            v.push_back(str);
        str = "";
        for(int i = v.size()-1; i >= 0; i--){
            str += v[i];
            if(i)
                str += " "; 
        }
        return str;
    }
};