class Solution {
public:
    int pFac[10][4] = {{0,0,0,0},{0,0,0,0},{1,0,0,0},{0,1,0,0},{2,0,0,0},{0,0,1,0},{1,1,0,0},{0,0,0,1},{3,0,0,0},{0,2,0,0}};
    int max2, max3, max5, max7;
    vector<vector<vector<vector<int>>>> minD;

    void subReq(vector<int>& req, int d) {
        for (int i = 0; i < 4; ++i) req[i] = max(0, req[i] - pFac[d][i]);
    }

    int getMin(int e2, int e3, int e5, int e7) {
        return minD[min(e2, max2)][min(e3, max3)][min(e5, max5)][min(e7, max7)];
    }

    string getSml(vector<int> req, int len) {
        string ans;
        for (int i = 0; i < len; ++i) {
            int rem = len - i - 1;
            for (int d = 1; d <= 9; ++d) {
                auto nxtReq = req;
                subReq(nxtReq, d);
                if (getMin(nxtReq[0], nxtReq[1], nxtReq[2], nxtReq[3]) <= rem) {
                    ans += to_string(d);
                    req = nxtReq;
                    break;
                }
            }
        }
        return ans;
    }

    string smallestNumber(string num, long long t) {
        vector<int> req(4, 0);
        int prm[] = {2, 3, 5, 7};
        for (int i = 0; i < 4; ++i) {
            while (t % prm[i] == 0) { 
                req[i]++; 
                t /= prm[i]; 
            }
        }
        if (t > 1) return "-1";
        
        max2 = req[0]; max3 = req[1]; max5 = req[2]; max7 = req[3];
        minD.assign(max2 + 1, vector<vector<vector<int>>>(max3 + 1, vector<vector<int>>(max5 + 1, vector<int>(max7 + 1, 1e9))));
        minD[0][0][0][0] = 0;
        int totReq = max2 + max3 + max5 + max7;
        
        for (int curSum = 1; curSum <= totReq; ++curSum) {
            for (int i = 0; i <= max2; ++i)
            for (int j = 0; j <= max3; ++j)
            for (int k = 0; k <= max5; ++k)
            for (int l = 0; l <= max7; ++l) {
                if (i + j + k + l != curSum) continue;
                int bestMin = 1e9;
                for (int d = 2; d <= 9; ++d) {
                    int p2 = max(0, i - pFac[d][0]), p3 = max(0, j - pFac[d][1]);
                    int p5 = max(0, k - pFac[d][2]), p7 = max(0, l - pFac[d][3]);
                    if (minD[p2][p3][p5][p7] != 1e9) {
                        bestMin = min(bestMin, minD[p2][p3][p5][p7] + 1);
                    }
                }
                minD[i][j][k][l] = bestMin;
            }
        }
        
        int nStr = num.size();
        bool hasZero = false;
        for (char c : num) {
            if (c == '0') { hasZero = true; break; }
        }
        
        if (!hasZero) {
            auto curReq = req;
            for (char c : num) subReq(curReq, c - '0');
            if (curReq[0] == 0 && curReq[1] == 0 && curReq[2] == 0 && curReq[3] == 0) return num;
        }
        
        vector<vector<int>> prefReq(nStr + 1);
        prefReq[0] = req;
        for (int i = 0; i < nStr; ++i) {
            prefReq[i + 1] = prefReq[i];
            if (num[i] != '0') subReq(prefReq[i + 1], num[i] - '0');
        }
        
        int lastIdx = hasZero ? num.find('0') : nStr - 1;
        string ansStr;
        
        for (int p = lastIdx; p >= 0 && ansStr.empty(); --p) {
            for (int d = num[p] - '0' + 1; d <= 9; ++d) {
                auto nxtReq = prefReq[p];
                subReq(nxtReq, d);
                int remDigs = nStr - p - 1;
                if (getMin(nxtReq[0], nxtReq[1], nxtReq[2], nxtReq[3]) <= remDigs) {
                    ansStr = num.substr(0, p) + to_string(d) + getSml(nxtReq, remDigs);
                    break;
                }
            }
        }
        
        if (!ansStr.empty()) return ansStr;
        
        int newLen = max(nStr + 1, getMin(req[0], req[1], req[2], req[3]));
        return getSml(req, newLen);
    }
};