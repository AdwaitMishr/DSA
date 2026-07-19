class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans = "";
        vector<int> freq(26), vis(26);
        for(char c : s) freq[c - 'a']++;
        for(char c : s) {
            if(!vis[c - 'a']) {
                while(!ans.empty() && ans.back() > c) {
                    if(freq[ans.back() - 'a'] > 0) {
                        vis[ans.back() - 'a'] = 0;
                        ans.pop_back();
                    }
                    else break;
                }
                vis[c - 'a'] = 1;
                ans += c;
            }
            freq[c - 'a']--;
        }
        return ans;
    }
};