class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        int copy = 0;
        for(auto& x: nums) {
            if(x < pivot) {
                ans.push_back(x);
            }else if(x == pivot) copy++;
        }
        while(copy) {
            ans.push_back(pivot);
            copy--;
        }
        for(auto& x: nums) {
            if(x > pivot) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};