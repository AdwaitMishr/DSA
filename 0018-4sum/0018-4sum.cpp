class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n - 3; i++) {
            if(i > 0 && nums[i - 1] == nums[i]) continue;
            for(int j = i + 1; j < n - 2; j++) {
                if(j > i + 1 && nums[j - 1] == nums[j]) continue;
                int s = j + 1, e = n - 1;
                while(s < e) {
                long long sum = (long long)nums[i] + nums[j] + nums[s] + nums[e];
                if(sum == target) {
                    ans.push_back({nums[i], nums[j], nums[s], nums[e]});
                    s++;
                    e--;
                    while(s < e && nums[s - 1] == nums[s]) s++;
                    while(s < e && nums[e] == nums[e + 1]) e--;
                }
                else if(sum > target) e--;
                else s++;

            }
            }
        }
        return ans;
    }
};