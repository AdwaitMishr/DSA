class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        set<char> s;
        for(char c : word) {
            s.insert(c);
        }
        for(char c = 'a'; c <= 'z'; c++) {
            if(s.find(c) != s.end()) {
                if(s.find(c - 32) != s.end()) ans++;
            }
        }
        return ans;
    }
};