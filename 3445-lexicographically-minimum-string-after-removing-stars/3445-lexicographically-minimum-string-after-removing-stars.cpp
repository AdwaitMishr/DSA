class Solution {
public:
    string clearStars(string s) {
        unordered_map<char, stack<int>> charIndex;
        string temp;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                charIndex[s[i]].push(temp.size());
                temp += s[i];
            } else {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (!charIndex[c].empty()) {
                        temp[charIndex[c].top()] = '.';
                        charIndex[c].pop();
                        break;
                    }
                }
            }
        }
        
        string result;
        for (char c : temp) {
            if (c != '.' && c != '*') result += c;
        }
        
        return result;
    }
};
