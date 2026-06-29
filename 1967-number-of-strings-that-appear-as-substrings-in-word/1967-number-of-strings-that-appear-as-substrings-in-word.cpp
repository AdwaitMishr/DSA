class Solution {
public:
    bool isPat(string p, string w) {
        int m = p.size();
        int n = w.size();
        for(int i = 0; i + m <= n; i++) {
            bool f = true;
            for(int j = 0; j < m; j++) {
                if(w[i + j] != p[j]) {
                    f = false;
                    break;
                }
            }
            if(f) return true;
        }
        return false;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for(auto p : patterns) ans += isPat(p, word);
        return ans;
    }
};