#define MOD 1000000007
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int range = r - l + 1;
        vector<int> dp0(range + 1, 0);
        vector<int> dp1(range + 1, 0);
        vector<int> sum0(range + 1, 0);
        vector<int> sum1(range + 1, 0);
        for(int i = 0; i < range; i++) dp0[i] = dp1[i] = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < range; j++) {
                sum0[j + 1] = (sum0[j] + dp0[j]) % MOD;
                sum1[j + 1] = (sum1[j] + dp1[j]) % MOD; 
            }
            for(int j = 0; j < range; j++) {
                dp0[j] = (sum1[range] - sum1[j + 1] + MOD) % MOD;
                dp1[j] = sum0[j];
            }
        }
        auto modAdd = [](int a, int b) {return (a + b) % MOD;};
        auto ans0 = reduce(begin(dp0), end(dp0), 0, modAdd);
        auto ans1 = reduce(begin(dp1), end(dp1), 0, modAdd);
        return (ans0 + ans1) % MOD;
    }
};