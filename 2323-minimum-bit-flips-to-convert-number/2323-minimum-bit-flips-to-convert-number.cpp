class Solution {
public:
    vector<int> decTobin(int n) {
        vector<int> ans(32,0);
        int i = 31;
        while(n) {
            ans[i] = n % 2;
            n = n /2;
            i--;
        }
        return ans;
    }
    int minBitFlips(int start, int goal) {
        vector<int> s = decTobin(start);
        vector<int> g = decTobin(goal);
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            if(s[i] != g[i])
                ans++;
        }
        return ans;
    }
};