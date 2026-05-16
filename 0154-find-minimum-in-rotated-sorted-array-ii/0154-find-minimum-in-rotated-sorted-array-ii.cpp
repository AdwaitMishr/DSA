class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        while(s < e) {
            int mid = s + ((e - s) >> 1);
            if(nums[mid] < nums[e]) e = mid;
            else if(nums[mid] == nums[e]) e = e - 1;
            else s = mid + 1;
        }
        return nums[s];
    }
};