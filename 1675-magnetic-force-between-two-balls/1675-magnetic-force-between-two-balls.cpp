class Solution {
public:
    bool Poss(vector<int>& position,int m,int mid){
          int ball=1;
          int ballpos=position[0];
          for(int i=0;i<position.size();i++){
              if(position[i]-ballpos>=mid){
                  ball++;
                  if(ball==m){
                      return true;
                  }
                  ballpos=position[i];
              }
          }
          return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int start=0;
        int end=*max_element(position.begin(),position.end());
        int ans=-1;
        int mid;
        while(start<=end){
            mid=start+(end-start)/2;
            if(Poss(position,m,mid)){
                ans=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }return ans;
    }
};