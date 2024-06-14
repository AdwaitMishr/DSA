class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int> mp(200001);
        int moves=0;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        for(int i=0;i<mp.size()-1;i++){
        if(mp[i]>1){
            mp[i+1]=mp[i+1]+(mp[i]-1);
            moves+=mp[i]-1;
            mp[i] = 1;
        }
        }  
        
   
        return moves;
        }
};