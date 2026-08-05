constexpr int maxN = 100005;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> inDeg(n);
        bitset<maxN> vis;
        for (auto &e : invocations) {
            adj[e[0]].push_back(e[1]);
            inDeg[e[1]]++;
        }
        queue<int> q;
        q.push(k);
        vis.set(k);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                inDeg[v]--;
                if (!vis.test(v)) {
                    vis.set(v);
                    q.push(v);
                }
            }
        }

        bool ok = true;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (vis.test(i) && inDeg[i] > 0) {
                ok = false;
                break;
            }
            if (!vis.test(i)) {
                ans.push_back(i);
            }
        }
        if (!ok) {
            ans.resize(n);
            iota(ans.begin(), ans.end(), 0);
        }
        return ans;
    }
};