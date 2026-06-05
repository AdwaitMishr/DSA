class Solution {
    long long dpC[20][10][10];
    long long dpS[20][10][10];
    string str;

    pair<long long, long long> dfs(int p, int pr, int c, bool lim, bool ld) {
        if (p == str.size()) {
            return {1, 0};
        }
        
        if (!lim && !ld && pr >= 0 && c >= 0) {
            if (dpC[p][pr][c] != -1) {
                return {dpC[p][pr][c], dpS[p][pr][c]};
            }
        }

        long long tC = 0, tS = 0;
        int up = lim ? str[p] - '0' : 9;

        for (int d = 0; d <= up; ++d) {
            bool nLd = ld && (d == 0);
            int nPr = c;
            int nC = nLd ? -1 : d;

            pair<long long, long long> sub = dfs(p + 1, nPr, nC, lim && (d == up), nLd);
            long long sC = sub.first;
            long long sS = sub.second;

            if (!nLd && pr >= 0 && c >= 0) {
                if ((pr < c && c > d) || (pr > c && c < d)) {
                    sS += sC;
                }
            }

            tC += sC;
            tS += sS;
        }

        if (!lim && !ld && pr >= 0 && c >= 0) {
            dpC[p][pr][c] = tC;
            dpS[p][pr][c] = tS;
        }

        return {tC, tS};
    }

    long long solve(long long n) {
        if (n < 100) return 0;
        str = to_string(n);
        memset(dpC, -1, sizeof(dpC));
        memset(dpS, -1, sizeof(dpS));
        return dfs(0, -1, -1, true, true).second;
    }

public:
    long long totalWaviness(long long n1, long long n2) {
        return solve(n2) - solve(n1 - 1);
    }
};