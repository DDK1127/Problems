// LeetCode 402.Remove K Digits
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(!num.length() || num.length() == k)
            return "0";
        if(!k)
            return num;

        string str = "";
        stack<char> ss;

        for(int i = 0; i < num.length(); i++){
            while(!ss.empty() && ss.top() > num[i] && k ){
                ss.pop();
                k--;
            }
            ss.push(num[i]);

            if(ss.size() == 1 && num[i] == '0')
                ss.pop();

        }
        while(k-- && !ss.empty())
            ss.pop();

        if(ss.empty())
            return "0";
        
        while(!ss.empty()){
            str += ss.top();
            ss.pop();
        }
        reverse(str);

        return str;
    }
    void reverse(string &str){
        int l = 0, r = str.size()-1;
        while(l < r){
            swap(str[l], str[r]);
            l++, r--;
        }
    }
};
