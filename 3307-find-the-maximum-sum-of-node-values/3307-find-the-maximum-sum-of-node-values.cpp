class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        int changed = 0;
        int minDiff = INT_MAX;
        for(auto& x : nums) {
            sum += max(x, x^k);
            changed += ((x ^ k) > x) ? 1 : 0;
            minDiff = min(minDiff, abs(x - (x ^ k))); 
        }
        if(changed % 2 == 0)
            return sum;
        return sum - minDiff;   
    }
};