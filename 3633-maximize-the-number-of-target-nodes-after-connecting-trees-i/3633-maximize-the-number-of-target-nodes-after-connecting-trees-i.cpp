class Solution {
public:
    int countReachable(int curr, int prev, const vector<vector<int>>& graph, int steps) {
        if (steps < 0) return 0;
        int total = 1;
        for (int next : graph[curr]) {
            if (next != prev) {
                total += countReachable(next, curr, graph, steps - 1);
            }
        }
        return total;
    }

    vector<int> getReachCounts(const vector<vector<int>>& edgeList, int limit) {
        int size = edgeList.size() + 1;
        vector<vector<int>> graph(size);
        for (const auto& e : edgeList) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> reachable(size);
        for (int i = 0; i < size; ++i) {
            reachable[i] = countReachable(i, -1, graph, limit);
        }
        return reachable;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& tree1, vector<vector<int>>& tree2, int k) {
        int n = tree1.size() + 1;
        vector<int> reach1 = getReachCounts(tree1, k);
        vector<int> reach2 = getReachCounts(tree2, k - 1);
        int best = *max_element(reach2.begin(), reach2.end());
        
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = reach1[i] + best;
        }
        return result;
    }
};
