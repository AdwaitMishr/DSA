class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        string temp = "";
        for(int i = 0; i < nums.size(); i++) {
            temp += to_string(nums[i]);
        }
        int n = size(temp);
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            ans[i] = temp[i] - '0';
        }
        return ans;
    }
};