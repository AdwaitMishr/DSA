class Solution {
private:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool isValid(int r, int c, int n) {
        return r >= 0 && c >= 0 && r < n && c < n;
    }
    void computeSafeness(vector<vector<int>>& g, int n) {
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 1) {
                    q.push({i, j});
                    g[i][j] = 0;
                } else {
                    g[i][j] = -1;
                }
            }
        }
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                if (isValid(nr, nc, n) && g[nr][nc] == -1) {
                    g[nr][nc] = g[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    bool checkPath(vector<vector<int>>& g, int minS, int n) {
        if (g[0][0] < minS || g[n - 1][n - 1] < minS) {
            return false;
        }
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));        
        q.push({0, 0});
        vis[0][0] = true;
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            if (r == n - 1 && c == n - 1) {
                return true;
            }
            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                if (isValid(nr, nc, n) && !vis[nr][nc] && g[nr][nc] >= minS) {
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& g) {
        int n = g.size();
        computeSafeness(g, n);
        int low = 0, high = 0, ans = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                high = max(high, g[i][j]);
            }
        }
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (checkPath(g, mid, n)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};