class Solution {
public:
    bool isGood(vector<int>& nums) {
       int n = nums.size() - 1;
       int maxEle = 0;
       for(int i = 0; i <= n; i++) {
        int val = abs(nums[i]);
        if(val > n) return false;
        if(val == n) maxEle++;
        else {
            if(nums[val] < 0) return false;
            nums[val] = -nums[val];
        }
       }
       return maxEle == 2;
    }
};