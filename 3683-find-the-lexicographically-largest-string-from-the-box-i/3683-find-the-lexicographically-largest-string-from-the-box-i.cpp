class Solution {
public:
    string answerString(string word, int n) {
        if(n == 1) return word;
        string res = "";
        for(int i = 0; i < word.length(); i++) {
            res = max(res, word.substr(i, word.length() - n + 1));
        } 
        return res;
    }
};