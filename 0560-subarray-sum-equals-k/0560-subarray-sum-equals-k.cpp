class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     unordered_map<int,int> mp;
     int sum=0;
     mp[0]=1;
     int c=0;
     for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        int r=sum-k;
        c+=mp[r];
        mp[sum]+=1;
        }
     
     return c;
    }
};