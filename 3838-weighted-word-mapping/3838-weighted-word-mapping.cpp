class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        int n = words.size();
        for(int i = 0; i < n; i++) {
            int wt = 0;
            for(int j = 0; j < words[i].size(); j++) {
                wt += weights[words[i][j] - 'a'];
            }
            ans += (char)('z' - wt%26);
        }
        return ans;
    }
};