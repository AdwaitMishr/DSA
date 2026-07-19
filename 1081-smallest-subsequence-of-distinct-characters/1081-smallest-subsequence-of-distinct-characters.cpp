class Solution {
public:
    string smallestSubsequence(string s) {
        string ans;
        vector<int> vis(26), alpha(26);
        for(char c : s) alpha[c - 'a']++;
        for(char c : s) {
            if(!vis[c - 'a']) {
                while(!ans.empty() && ans.back() > c) {
                    if(alpha[ans.back() - 'a'] > 0) {
                        vis[ans.back() - 'a'] = 0;
                        ans.pop_back();
                    } else break;
                }
                vis[c - 'a'] = 1;
                ans += c;
            }
            alpha[c - 'a'] -= 1;
        }
        return ans;
    }
};