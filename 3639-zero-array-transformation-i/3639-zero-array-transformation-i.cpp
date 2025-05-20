class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> delta(n + 1, 0);

        for(auto& q: queries) {
            int l = q[0], r = q[1];
            delta[l] += 1;
            if(r + 1 < n) delta[r+1] -= 1; 
        }
        int prefixSum = 0;
        for(int i = 0; i < n; i++) {
            prefixSum += delta[i];
            if(nums[i] > prefixSum) return false;
        }
        return true;
    }
};