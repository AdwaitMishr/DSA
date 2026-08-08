class Solution {
public:
    vector<int> validSequence(string w1, string w2) {
        int n = w1.size(), m = w2.size(), j = m - 1, skp = 0;
        vector<int> lst(m, -1), ans;
        for (int i = n - 1; i >= 0 && j >= 0; --i)
            if (w1[i] == w2[j]) lst[j--] = i;
        j = 0;
        for (int i = 0; i < n && j < m; ++i) {
            if (w1[i] == w2[j] || (!skp && (j == m - 1 || i < lst[j + 1]))) {
                skp += w1[i] != w2[j];
                ans.push_back(i);
                ++j;
            }
        }
        return j == m ? ans : vector<int>();
    }
};