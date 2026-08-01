class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26, 0);
        for(char c : word) mp[c - 'a']++;
        sort(mp.rbegin(), mp.rend());
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            if(!mp[i]) break;
            ans += (((i >> 3) + 1) * mp[i]);
        }
        return ans;
    }
};