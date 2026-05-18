class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        int n = arr.size();
        for(int i = 0; i < n; i++) mp[arr[i]].push_back(i);
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        int ans = 0;
        vis[0] = true;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int head = q.front(); q.pop();
                if(head == n - 1) return ans;
                if(head + 1 < n && !vis[head + 1]) {
                    vis[head + 1] = true;
                    q.push(head + 1);
                    }
                if(head - 1 >= 0 && !vis[head - 1]) {
                    vis[head - 1] = true;
                    q.push(head - 1);
                    }
                for(int idx : mp[arr[head]]) {
                    if(!vis[idx]) {
                        q.push(idx);
                        vis[idx] = true;
                    }
                }
                mp[arr[head]].clear();
            }
            ans++;
        }
        return -1;
    }
};