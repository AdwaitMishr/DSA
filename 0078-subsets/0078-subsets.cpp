class Solution {
public:
    void subsets(vector<int>& nums,vector<vector<int>>& ans,vector<int> temp,int i)
    {
        if(i>=nums.size()){
            ans.push_back(temp);
            return;
        }
        //exclude
        subsets(nums,ans,temp,i+1);
        //include
        int el=nums[i];
        temp.push_back(el);
        subsets(nums,ans,temp,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int index=0;
        subsets(nums,ans,temp,index);
        return ans;
    }
};