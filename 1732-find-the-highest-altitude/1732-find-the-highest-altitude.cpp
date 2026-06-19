class Solution {
public:
    int largestAltitude(vector<int>& gain) {
      int ans = 0;
      int prefixSum = 0;
      for(int x : gain) {
        prefixSum += x;
        ans = max(ans, prefixSum);
      }  
      return ans;
    }
};