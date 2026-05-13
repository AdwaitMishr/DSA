class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int ans = INT_MAX;
        int n = size(nums);
        vector<int> delta(2 * limit + 2, 0);
        for(int i = 0; i < (n >> 1); i++) {
            int A = min(nums[i], nums[n - i - 1]);
            int B = max(nums[i], nums[n - i - 1]);
            delta[2] += 2;
            delta[A + 1] -= 1;
            delta[A + B] -= 1;
            delta[A + B + 1] += 1;
            delta[B + limit + 1] += 1;
        }
        int temp = 0;
        for(int i = 2; i <= 2 * limit; i++) {
            temp += delta[i];
            ans = min(ans, temp);
        }
        return ans;
    }
};