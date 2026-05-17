class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= size(s)) return s;
        int i = 0, d = 1;
        vector<vector<char>> grid(numRows);
        for(char c : s) {
            grid[i].push_back(c);
            if(i == 0) d = 1;
            else if( i == numRows - 1) d = -1;
            i += d;
        }
        string ans = "";
        for(auto g : grid) {
            for(char c : g) ans += c;
        }
        return ans;
    }
};