class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n  = grid.size();
        if(n == 1) return 0;
        vector<vector<long long>> S(n + 1 ,vector<long long>(n + 1, 0)), D(n + 1 ,vector<long long>(n + 1, 0)), P = D, M = D;
        for(int c = 0; c < n; c++){
            for(int r = 0; r < n; r++) S[c][r + 1] = S[c][r] + grid[r][c];
        } 
        for(int i = 1; i < n; i++) {
            vector<vector<long long>> Q(n + 1, vector<long long>(n + 1, 0));
            for(int c = 0; c <= n; c++)
            for(int p = 0; p <= n; p++) 
            Q[c][p] = max(0LL, c <= p ? M[p][0] + S[i][p] - S[i][c] : max(M[p][c], P[p][c] + S[i - 1][c] - S[i - 1][p]));
            for(int c = 0; c <= n; c++) {
                P[c][0] = Q[c][0];
                M[c][n] = Q[c][n];
                for(int p = 1; p <= n; p++) P[c][p] = max(P[c][p-1], Q[c][p] - (p > c ? S[i][p] - S[i][c] : 0));
                for(int p = n - 1; p >= 0; --p) M[c][p] = max(M[c][p+1], Q[c][p]);
            }
            D = move(Q);
        }
        long long ans = 0;
        for(int i = 0; i <= n; i++) ans = max({ans, D[n][i], D[0][i]});
        return ans;
    }
};