class Solution {
public:
    int minimumEffort(vector<vector<int>>& task) {
        sort(task.begin(), task.end(), [](vector<int>& a, vector<int>& b) {
            int gap1 = a[1] - a[0];
            int gap2 = b[1] - b[0];
            return gap1 < gap2;
        });
        int ans = 0;
        for(int i = 0; i < task.size(); i++) {
            if(ans + task[i][0] >= task[i][1]) ans += task[i][0];
            else ans = task[i][1];
        }
        return ans;
    }
};