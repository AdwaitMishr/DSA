class Solution {
public:
    bool dfs(vector<int>& nums, int left, int right, int chance, int sum1, int sum2) {
        if(left > right) return sum1 >= sum2;
        if(chance) {
            return (dfs(nums, left + 1, right, !chance, sum1 + nums[left], sum2) ||dfs(nums, left, right - 1, !chance, sum1 + nums[right], sum2));
        }
        else return (dfs(nums, left + 1, right, !chance, sum1, nums[left] + sum2) && dfs(nums, left, right - 1, !chance, sum1 ,  nums[right] + sum2));
        return true;
    }
    bool predictTheWinner(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int left = 0, right = nums.size() - 1;
        return dfs(nums, left, right, 1, 0, 0);
    }
};