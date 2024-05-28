class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        vector<int> copy;
        int cond=nums.size()/3;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==1){
                copy.push_back(nums[i]);
            }
        }
        for(int i=0;i<copy.size();i++){
            if(mp[copy[i]]>cond){
                ans.push_back(copy[i]);
            }
            }
        
        return ans;
    }
};