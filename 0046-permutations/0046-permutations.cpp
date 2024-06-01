class Solution {
public:
    void sol(vector<vector<int>> &ans,vector<int>& nums,int i){
        if(i>=nums.size()){
            ans.push_back(nums);
             return;
             }
            for(int j=i;j<nums.size();j++){
                swap(nums[j],nums[i]);
                sol(ans,nums,i+1);
                swap(nums[j],nums[i]);

            }
           
        }


    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        sol(ans,nums,index);
        return ans;
    }
};