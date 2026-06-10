class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLog = 18; 
        vector<vector<int>> stMax(n, vector<int>(maxLog));
        vector<vector<int>> stMin(n, vector<int>(maxLog));
        vector<int> lg(n + 1);
        lg[1] = 0;
        for (int i = 2; i <= n; ++i) lg[i] = lg[i / 2] + 1;
        for (int i = 0; i < n; ++i) {
            stMax[i][0] = nums[i];
            stMin[i][0] = nums[i];
        }
        for (int j = 1; j < maxLog; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                stMax[i][j] = max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
                stMin[i][j] = min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
            }
        }
        auto getVal = [&](int l, int r) -> long long {
            int j = lg[r - l + 1];
            long long mx = max(stMax[l][j], stMax[r - (1 << j) + 1][j]);
            long long mn = min(stMin[l][j], stMin[r - (1 << j) + 1][j]);
            return mx - mn;
        };
        priority_queue<pair<long long, pair<int, int>>> pq;
        for (int i = 0; i < n; ++i) {
            pq.push({getVal(i, n - 1), {i, n - 1}});
        }
        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            auto top = pq.top();
            pq.pop();
            ans += top.first;
            int l = top.second.first;
            int r = top.second.second;
            if (r > l) {
                pq.push({getVal(l, r - 1), {l, r - 1}});
            }
        }
        
        return ans;
    }
};