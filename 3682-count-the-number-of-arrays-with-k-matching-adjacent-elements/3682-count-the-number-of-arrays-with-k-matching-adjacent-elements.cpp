#define MOD 1000000007
#define MX 100005

vector<int> f(MX), invf(MX);
class Solution {
public:



int power(int base, int exp) {
    int res = 1;
    base %= MOD;
    while(exp > 0) {
        if(exp & 1) res = (1LL * res * base) % MOD;
        base = (1LL * base * base) % MOD;
        exp >>=1;
    }
    return res;
}

int inverse(int a) {
    return power(a, MOD - 2);
}
void initFactorial() {
    f[0] = 1;
    for(int i = 1; i < MX; i ++) {
        f[i] = 1LL *  f[i - 1] * i % MOD;
    }
    invf[MX - 1] = inverse(f[MX - 1]);
    for(int i = MX - 2; i >= 0; i--) {
        invf[i] = 1LL * invf[i + 1] * (i + 1) % MOD;
    }
}
int nCr(int n, int r) {
    if(r < 0 || r > n) return 0;
    return 1LL * f[n] * invf[r] % MOD * invf[n - r] % MOD;
}
    int countGoodArrays(int n, int m, int k) {
        initFactorial();
        int res = m % MOD;
        res = 1LL * res * nCr(n - 1, k) % MOD;
        int powerTerm = (n == k + 1) ? 1 : power(m -1, n - k - 1);
        return 1LL * res * powerTerm % MOD;
    }
};