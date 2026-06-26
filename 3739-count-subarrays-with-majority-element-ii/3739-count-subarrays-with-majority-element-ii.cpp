class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pre(2 * n + 1, 0);
        pre[n] = 1; int count = n;
        long long ans = 0, prefixSum = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == target) {
                prefixSum += pre[count];
                count++;
                ++pre[count]; 
            } else {
                count--;
                prefixSum -= pre[count];
                ++pre[count];
            }
            ans += prefixSum;
        }
        return ans;
    }
};