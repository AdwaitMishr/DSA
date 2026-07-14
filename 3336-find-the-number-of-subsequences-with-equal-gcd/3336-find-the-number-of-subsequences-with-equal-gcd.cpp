class Solution {
const int MOD = 1e9 + 7;
public:
    int rec(int idx, int s1, int s2, vector<int>& nums, vector<vector<vector<int>>>& dp) {
        if(idx == nums.size()) {
            if(s1 != 0 && s1 == s2) return 1;
            return 0;
        }
        if(dp[idx][s1][s2] != -1) return dp[idx][s1][s2];
        int ans = 0;
        ans = (ans + rec(idx + 1, __gcd(s1, nums[idx]), s2, nums, dp)) % MOD;
        ans = (ans + rec(idx + 1, s1, __gcd(nums[idx], s2), nums, dp)) % MOD;
        ans = (ans + rec(idx + 1, s1, s2, nums, dp)) % MOD;
        return dp[idx][s1][s2] = ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(201, vector<int>(201, -1)));
        return rec(0, 0, 0, nums, dp);
    }
};