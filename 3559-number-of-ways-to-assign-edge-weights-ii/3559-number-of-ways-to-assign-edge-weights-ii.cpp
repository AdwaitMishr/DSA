class TreeLca {
private:
    int n;
    int m;
    vector<int> dep;
    vector<vector<int>> adj;
    vector<vector<int>> up;

    void dfs(int x, int p) {
        up[x][0] = p;
        for (int y : adj[x]) {
            if (y != p) {
                dep[y] = dep[x] + 1;
                dfs(y, x);
            }
        }
    }

public:
    TreeLca(const vector<vector<int>>& edges, int rt = 1) {
        n = edges.size() + 1;
        m = 32 - __builtin_clz(n);
        adj.resize(n + 1);
        dep.resize(n + 1, 0);
        up.resize(n + 1, vector<int>(m, 0));

        for (const auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(rt, 0);

        for (int i = 1; i < m; i++) {
            for (int x = 1; x <= n; x++) {
                up[x][i] = up[up[x][i - 1]][i - 1];
            }
        }
    }

    int getLca(int x, int y) {
        if (dep[x] > dep[y]) {
            swap(x, y);
        }
        for (int i = m - 1; i >= 0; i--) {
            if (dep[x] <= dep[up[y][i]]) {
                y = up[y][i];
            }
        }
        if (x == y) {
            return x;
        }
        for (int i = m - 1; i >= 0; i--) {
            if (up[y][i] != up[x][i]) {
                x = up[x][i];
                y = up[y][i];
            }
        }
        return up[x][0];
    }

    int getDist(int x, int y) {
        return dep[x] + dep[y] - dep[getLca(x, y)] * 2;
    }
};

class Solution {
private:
    vector<int> getPow2(int maxLen, int modVal) {
        vector<int> p2(maxLen + 1, 1);
        for (int i = 1; i <= maxLen; i++) {
            p2[i] = (p2[i - 1] * 2) % modVal;
        }
        return p2;
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        TreeLca treeLca(edges, 1);
        int qLen = queries.size();
        int modVal = 1e9 + 7;

        vector<int> p2 = getPow2(edges.size() + 2, modVal);
        vector<int> res(qLen, 0);

        for (int i = 0; i < qLen; i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            if (x != y) {
                int d = treeLca.getDist(x, y);
                res[i] = p2[d - 1];
            }
        }
        return res;
    }
};