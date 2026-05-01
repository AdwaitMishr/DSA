class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);
        int Fx  = 0;
        for(int i = 0; i < n; i++) {
            Fx += i * nums[i];
        }
        int ans = Fx;
        for(int i = n - 1; i >= 0; i--) {
            Fx += sum - n * nums[i];
            ans = max(ans, Fx);
        }
        return ans;
    }
};