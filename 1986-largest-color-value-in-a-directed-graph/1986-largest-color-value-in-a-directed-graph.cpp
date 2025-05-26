class Solution {
public:
    int dfs(int u, string& s, vector<vector<int>>& graph, vector<vector<int>>& freq, vector<int>& state) {
        if (state[u] == 1) return INT_MAX;
        if (state[u] == 2) return freq[u][s[u] - 'a'];

        state[u] = 1;

        for (int v : graph[u]) {
            if (dfs(v, s, graph, freq, state) == INT_MAX) return INT_MAX;
            for (int i = 0; i < 26; i++) {
                freq[u][i] = max(freq[u][i], freq[v][i]);
            }
        }

        freq[u][s[u] - 'a']++;
        state[u] = 2;

        return freq[u][s[u] - 'a'];
    }

    int largestPathValue(string s, vector<vector<int>>& edgeList) {
        int n = s.size();
        vector<vector<int>> graph(n), freq(n, vector<int>(26));
        vector<int> state(n, 0);

        for (auto& edge : edgeList) {
            graph[edge[0]].push_back(edge[1]);
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            int val = dfs(i, s, graph, freq, state);
            if (val == INT_MAX) return -1;
            result = max(result, val);
        }

        return result;
    }
};
