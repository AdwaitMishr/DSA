class Solution {
private:
    int modVal = 1e9 + 7;
    void upd(vector<vector<pair<int, int>>>& dp, int n, int x, int y, int u, int v) {
        if (u >= n || v >= n || dp[u][v].first == -1) {
            return;
        }
        if (dp[u][v].first > dp[x][y].first) {
            dp[x][y] = dp[u][v];
        } else if (dp[u][v].first == dp[x][y].first) {
            dp[x][y].second += dp[u][v].second;
            if (dp[x][y].second >= modVal) {
                dp[x][y].second -= modVal;
            }
        }
    }
public:
    vector<int> pathsWithMaxScore(vector<string>& b) {
        int n = b.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));
        dp[n - 1][n - 1] = {0, 1};
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (!(i == n - 1 && j == n - 1) && b[i][j] != 'X') {
                    upd(dp, n, i, j, i + 1, j);
                    upd(dp, n, i, j, i, j + 1);
                    upd(dp, n, i, j, i + 1, j + 1);
                    if (dp[i][j].first != -1) {
                        dp[i][j].first += (b[i][j] == 'E' ? 0 : b[i][j] - '0');
                    }
                }
            }
        }
        if (dp[0][0].first == -1) {
            return {0, 0};
        }
        return {dp[0][0].first, dp[0][0].second};
    }
};