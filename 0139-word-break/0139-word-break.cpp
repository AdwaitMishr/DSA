class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1, false);
        dp[s.length()] = true;
        for(int i = s.length() - 1; i >=0 ; i--) {
            for(auto& words : wordDict) {
                if( i + words.length() <= s.length()  && s.substr(i,words.length()) == words) {
                    if(dp[i + words.length()]){
                    dp[i] = true;
                    break;
                    }
                }
            }
        }
        return dp[0];
    }
};