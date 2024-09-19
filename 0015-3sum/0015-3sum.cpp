class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int target = -nums[i];
            int start = i + 1;
            int end = nums.size() - 1;
            while(start < end) {
                if(target == nums[start] + nums[end]) {
                    ans.push_back({nums[i], nums[start], nums[end]});
                while(start < end && nums[start] == nums[start + 1])
                    start++;
                while(start < end && nums[end] == nums[end - 1])
                    end--;
                start++;    
                end--;
                }
                else if((nums[start] + nums[end]) < target)
                    start++;
                else
                    end--;     
            }    
        }
        return ans;
    }
};