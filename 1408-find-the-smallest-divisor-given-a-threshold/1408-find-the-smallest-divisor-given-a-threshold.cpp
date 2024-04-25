class Solution {
public:
    int max(vector<int>& nums){
        int max=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max)
            max=nums[i];
        }
        return max;
    }
    int divSum(vector<int>& nums, int mid){
        int sum=0;
        cout<<mid<<"----"<<endl;
        for(int i=0;i<nums.size();i++){
            sum+=ceil((double)nums[i]/(double)mid);
        }
        cout<<sum<<endl;
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1;
        int e=max(nums);
        int ans=-1;
        while(s<=e){
            int mid=(s+e)>>1;
            int val=divSum(nums,mid);
            if(val<=threshold){
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
        }
        return ans;
    }
};