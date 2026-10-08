class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n - 2; i++) {
            for(int j = i + 1; j < n - 1; j++) {
                for(int k = j + 1; k < n; k++) {
                    int temp = abs(target - (nums[i] + nums[j] + nums[k]));
                    if(temp < diff) {
                        diff = temp;
                        ans = nums[i] + nums[j] + nums[k];
                    }
                }
            }
        }
        return ans;
    }
};