class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int prefixSum = 0;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            ans.push_back(abs(prefixSum - sum));
            sum -= nums[i];
        }
        return ans;
    }
};