class Solution {
    bool isDuplicate(vector<int>& nums,int mid){
        bool odd=(mid&1)?true:false;
        if(mid+1>nums.size() && mid-1<0)
        return false;
        if(odd){
            if(nums[mid]==nums[mid-1])
            return true;
        }else{
            if(nums[mid]==nums[mid+1])
            return true;
        }
        return false;
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        while(s<e){
            int mid=(s+e)>>1;
            if(isDuplicate(nums,mid))
            s=mid+1;
            else
            e=mid;
        }
        return nums[s];
    }
};