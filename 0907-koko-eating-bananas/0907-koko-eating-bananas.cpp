class Solution {
public:
int max(vector<int>& piles){
    int max=INT_MIN;
    for(int i=0;i<piles.size();i++){
        if(piles[i]>max)
        max=piles[i];
    }    
 
    return max;
}
   long long timetaken(vector<int>& piles, int mid){
    long long thrs=0;
    for(int i=0;i<piles.size();i++){
        thrs=thrs+ceil((double)piles[i]/(double)mid);
        }
    return thrs;
   }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e=max(piles);
        int ans=-1;
        while(s<=e){
            int mid=(e+s)>>1;
            long long val=timetaken(piles,mid);
             if(val<=h){
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
        }
        return ans;
    }
};