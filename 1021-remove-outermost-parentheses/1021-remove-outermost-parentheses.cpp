class Solution {
public:
    string removeOuterParentheses(string s) {
        int score = 0;
        string ans = "";
        for(char c : s) {
            if(c == ')') score--;
            if(score) ans += c;
            if(c == '(') score++;
        }
        return ans;
    }
};