// LeetCode 1455.Check If a Word Occurs As a Prefix of Any Word in a Sentence

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord){
        int size = sentence.size(), stop = searchWord.size();
        int counter = 1, j = 0;
        bool start = true, result = false;
        for(int i = 0; i < size; i++){
            if(start){
                if(sentence[i] == searchWord[j++]){}
                else{
                    start = false;
                    j = 0;
                }
            }
            if(sentence[i] == ' '){
                counter++;
                start = true;
            }
            if(j == stop){
                cout << "j = " << j << endl;
                result = true;
                break;
            }
        }
        return (result)? counter:-1;
    }
};