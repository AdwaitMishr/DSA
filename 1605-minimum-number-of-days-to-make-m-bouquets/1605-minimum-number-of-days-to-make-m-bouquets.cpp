class Solution {
public:
    bool Poss(vector<int>& bloomDay, int m, int k, int mid) {
        int bouquets = 0;
        int flowers = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                ++flowers;
                if (flowers == k) {
                    ++bouquets;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans=-1;
        int start=*min_element(bloomDay.begin(), bloomDay.end());
        int end=*max_element(bloomDay.begin(), bloomDay.end());
        int mid;
        while(start<=end){
            mid=start+(end-start)/2;
            if(Poss(bloomDay,m,k,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};