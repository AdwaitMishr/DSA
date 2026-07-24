class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int m = 1;
        while(m <= maxi) m <<= 1;
        vector<bool> A(m, false);
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) A[nums[i] ^ nums[j]] = 1; 
        }
        vector<int> B(m);
        for(int i = 0; i < m; i++ ) {
            if(!A[i]) continue;
            for(int x : nums) B[i ^ x] = 1;
        }
        int ans = 0;
        for(int i = 0; i < m; i++) {
            if(B[i]) ans++;
        }
        return ans;
    }
};