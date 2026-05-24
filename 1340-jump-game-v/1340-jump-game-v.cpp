class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> id(n);
        int ans = 1;
        for(int i = 0; i < n; i++) id[i] = i;
        sort(id.begin(), id.end(), [&arr](int a, int b) {
            return arr[a] < arr[b];
        });
        for (int i : id) {
            for (int j = i - 1; j >= 0 && i - j <= d && arr[i] > arr[j]; --j) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            for (int j = i + 1; j < n && j - i <= d && arr[i] > arr[j]; ++j) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};