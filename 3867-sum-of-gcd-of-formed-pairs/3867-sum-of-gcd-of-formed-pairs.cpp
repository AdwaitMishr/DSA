class Solution {
public:
    long long gcdSum(vector<int>& nums) {
      vector<long long> pref;
      long long maxi = INT_MIN;
      for(long long x : nums) {
        maxi = max(maxi, x);
        pref.push_back(__gcd(x, maxi));
      }
      long long ans = 0;
      sort(begin(pref), end(pref));
      int l = 0, r = nums.size() - 1;
      while(l < r) {
        ans += __gcd(pref[l], pref[r]);
        l++; r--;
      }
      return ans;
    }
};