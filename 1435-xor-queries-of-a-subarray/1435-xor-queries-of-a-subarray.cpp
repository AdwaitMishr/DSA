class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> x(n);
        x[0] = arr[0];
        for(int i = 1; i < arr.size(); i++) {
            x[i] = x[i-1] ^ arr[i]; 
        }
        int m = queries.size();
        vector<int> ans(m);
        for(int i = 0; i < m; i++) {
            int L = queries[i][0], R = queries[i][1];
            if(L == 0) {
                ans[i] = x[R]; 
            } else {
                ans[i] = x[R] ^ x[L - 1];  
            }
        }
        return ans;
    }
};