#define MOD 1000000007

class Solution {
    using Matrix = vector<vector<long long>>;
    Matrix multiply(Matrix& a, Matrix& b, int size) {
        Matrix c(size, vector<long long>(size, 0));
        for (int i = 0; i < size; i++) {
            for (int k = 0; k < size; k++) {
                if (a[i][k] == 0) continue; 
                for (int j = 0; j < size; j++) {
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }
        return c;
    }

    Matrix power(Matrix a, long long p, int size) {
        Matrix res(size, vector<long long>(size, 0));
        for (int i = 0; i < size; i++) res[i][i] = 1; 
        while (p > 0) {
            if (p & 1) res = multiply(res, a, size);
            a = multiply(a, a, size);
            p >>= 1;
        }
        return res;
    }
public:
    int zigZagArrays(int n, int l, int r) {
        if (n == 1) return ((r - l + 1) * 2) % MOD;
        int range = r - l + 1;
        Matrix trans(range, vector<long long>(range, 0));
        for (int j = 0; j < range; j++) {
            for (int c = range - j; c < range; c++) {
                trans[j][c] = 1;
            }
        }
        Matrix finalTrans = power(trans, n - 1, range);
        long long ans = 0;
        for (int i = 0; i < range; i++) {
            for (int j = 0; j < range; j++) {
                ans = (ans + finalTrans[i][j]) % MOD;
            }
        }
        return (ans * 2) % MOD;
    }
};