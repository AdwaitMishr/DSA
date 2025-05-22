class Solution {
public:
    int maxRemoval(vector<int>& demand, vector<vector<int>>& operations) {
        int n = demand.size();
        vector<int> deferred(n + 1, 0);
        priority_queue<int> available;
        int opCount = 0;

        sort(operations.begin(), operations.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        int idx = 0;

        for (int i = 0; i < n; ++i) {
            opCount += deferred[i];
            while (idx < operations.size() && operations[idx][0] == i) {
                available.push(operations[idx][1]);
                ++idx;
            }
            while (opCount < demand[i] && !available.empty() && available.top() >= i) {
                ++opCount;
                deferred[available.top() + 1] -= 1;
                available.pop();
            }
            if (opCount < demand[i]) {
                return -1;
            }
        }
        return available.size();
    }
};
