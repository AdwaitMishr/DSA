class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ans = 0;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                vis[i] = true;
                queue<int> q;
                q.push(i);
                int ver = 0, ed = 0;
                while(!q.empty()) {
                    int node = q.front(); q.pop();
                    ver++;
                    ed += adj[node].size();
                    for(int v : adj[node]) {
                        if(!vis[v]) {
                            vis[v] = true;
                            q.push(v);
                        }
                    }
                }
                if(ed == ver * (ver - 1)) ans++;
            }
        }
        return ans;
    }
};