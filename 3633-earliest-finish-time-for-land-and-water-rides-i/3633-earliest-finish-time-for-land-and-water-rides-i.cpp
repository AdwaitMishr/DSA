class Solution {
public:
    int calc(vector<int>& s1, vector<int>& d1, vector<int>& s2, vector<int>& d2) {
        vector<int> finish;
        for(int i = 0; i < s1.size(); i++) {
            finish.push_back(s1[i] + d1[i]);
        } 
        sort(finish.begin(), finish.end());
        int res = INT_MAX;
        for(int i = 0; i < s2.size(); i++) {
            auto it = lower_bound(finish.begin(), finish.end(), s2[i]);
            int maxi = INT_MAX;
            if(it != finish.end()) maxi = *it;
            if(it != finish.begin()) maxi = min(maxi, s2[i]);
            if(maxi != INT_MAX) {
                int ans = maxi + d2[i];
                res = min(res, ans);
            }
            
            
        }
        return res;
        
    }
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        return min(calc(ls, ld, ws, wd), calc(ws, wd, ls, ld));
    }
};