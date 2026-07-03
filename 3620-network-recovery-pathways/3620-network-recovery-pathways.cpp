class Solution {
private: 
    bool isPoss(int mid, int n, long long k, vector<vector<pair<int, int>>>& adj, vector<int>& topoSort, vector<bool>& online ) {
        long long maxi = LLONG_MAX;
        vector<long long> dist(n , maxi);
        dist[0] = 0;
        for(int u : topoSort) {
            if(!online[u] || dist[u] == maxi) continue;
            for(auto [v , c] : adj[u]) {
                if(c < mid || !online[v]) continue;
                dist[v] = min(dist[v], dist[u] + c);
            }
        }
        return dist[n - 1] <= k;
    }
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        vector<int> indegree(n , 0);
        for(auto e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            indegree[e[1]]++;
        }
        vector<int> topoSort;
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int u = q.front(); q.pop();
            topoSort.push_back(u);
            for(auto [v , c] : adj[u]) 
                if(--indegree[v] == 0) q.push(v);
        }
        int left = 0, right = 0;
        for(auto e : edges) right = max(right, e[2]);
        int ans = -1;
        while( left <= right) {
            int mid =  left + ((right - left) >> 1);
            if(isPoss(mid, n, k, adj, topoSort, online)) {
                ans = mid;
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        return ans;
        
    }
};