class Solution {
struct DSU{
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    bool unionByRank(int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v) return false;
        if(rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if(rank[u] == rank[v]) rank[u]++;
        return true;
    }
};
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;
        DSU dsu(n);
        for(int i = 1; i < n; i++) {
            if(nums[i] - nums[i - 1] <= maxDiff) dsu.unionByRank(i, i - 1);
        }
        for(auto& it : queries) {
            ans.push_back(dsu.find(it[0]) == dsu.find(it[1]));
        }
        return ans;
    }
};