using ll = long long;
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;
        int n = basket1.size();
        for (int i = 0; i < n; ++i) {
            freq[basket1[i]]++;
            freq[basket2[i]]++;
        }
       
        for (auto& [x, cnt] : freq)
            if (cnt % 2) return -1;

        
        unordered_map<int, int> s1, s2;
        for (int i = 0; i < n; ++i) {
            if (basket1[i] != basket2[i]) {
                s1[basket1[i]]++;
                s2[basket2[i]]++;
            }
        }

        vector<int> extra1, extra2;
        for (auto& [x, cnt] : s1) {
            int need = cnt - s2[x];
            if (need > 0) {
                for (int i = 0; i < need / 2; ++i)
                    extra1.push_back(x);
            }
        }
        for (auto& [x, cnt] : s2) {
            int need = cnt - s1[x];
            if (need > 0) {
                for (int i = 0; i < need / 2; ++i)
                    extra2.push_back(x);
            }
        }

        sort(extra1.begin(), extra1.end());
        sort(extra2.rbegin(), extra2.rend()); 
        int globalMin = INT_MAX;
        for (auto& [x, cnt] : freq)
            globalMin = min(globalMin, x);

        ll ans = 0;
        int m = extra1.size();
        for (int i = 0; i < m; ++i) {
            int a = extra1[i];
            int b = extra2[i];
            int direct = min(a, b);
            ll global = 2LL * globalMin;
            ans += min<ll>(direct, global);
        }
        return ans;
    }
};
