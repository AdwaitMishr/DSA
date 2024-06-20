class Solution {
public:
    bool Poss(int n, vector<int>& quantities, int mid){
        for(int i = 0;i < quantities.size(); i++) {
          int product = quantities[i];
          n -= (product/mid);
          if(product%mid != 0)
          n--;
          
          if(n<0)
          return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int s=1;
        int e=*max_element(quantities.begin(), quantities.end());
        int ans=-1;
        int mid;
        while(s<=e){
            mid=(s+e)>>1;
         
            if(Poss(n,quantities,mid)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};