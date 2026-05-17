class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        int n = arr.size();
        vector<bool> vis(n, false);
        vis[start] = true;
        while(!q.empty()) {
            int head = q.front(); q.pop();
            if(arr[head] == 0) return true;
            if(head - arr[head] >= 0 && !vis[head - arr[head]]) {
                vis[head - arr[head]] = true;
                q.push(head - arr[head]);
                }
            if(head + arr[head] < n && !vis[head + arr[head]]) {
                vis[head + arr[head]] = true;
                q.push(head + arr[head]);
                }
        }
        return false;
    }
};