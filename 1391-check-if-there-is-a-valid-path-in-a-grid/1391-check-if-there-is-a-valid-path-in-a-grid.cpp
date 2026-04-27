class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        unordered_map<int, vector<pair<int,int>>> dir = {
            {1, {{0, -1}, {0, 1}}},   
            {2, {{-1, 0}, {1, 0}}},   
            {3, {{0, -1}, {1, 0}}},   
            {4, {{0, 1}, {1, 0}}},    
            {5, {{0, -1}, {-1, 0}}},  
            {6, {{0, 1}, {-1, 0}}}    
            };
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push({0,0});
        vis[0][0] = true;
        while(!q.empty()) {
            auto[x, y] = q.front(); q.pop();
            if(x == n - 1 && y == m - 1) return true;
            for(auto[dx, dy] : dir[grid[x][y]]) {
                int ndx = dx + x;
                int ndy = dy + y;
                if(ndx >= 0 && ndx < n && ndy >= 0 && ndy < m && !vis[ndx][ndy]) {
                    for(auto[rx, ry] : dir[grid[ndx][ndy]]) {
                        if(ndx + rx == x && ndy + ry == y) {
                            vis[ndx][ndy] = true;
                            q.push({ndx, ndy});
                            break;
                        }
                    }
                }
            }
        }
        return false;
    }
};