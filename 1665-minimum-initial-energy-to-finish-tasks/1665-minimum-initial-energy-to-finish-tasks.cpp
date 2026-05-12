class Solution {
public:
    int minimumEffort(vector<vector<int>>& task) {
        sort(task.begin(), task.end(), [](const vector<int>& a, const vector<int>& b) {
            int gap1 = a[1] - a[0];
            int gap2 = b[1] - b[0];
            return gap1 < gap2;
        });
        int ans = 0;
        for(int i = 0; i < task.size(); i++) {
            ans = max(ans + task[i][0], task[i][1]);
        }
        return ans;
    }
};