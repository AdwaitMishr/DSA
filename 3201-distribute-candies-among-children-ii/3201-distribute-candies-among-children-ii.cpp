class Solution {
public:
    long long nCr(int x) {
        if(x < 0) return 0;
        return (long)x * (x-1)/2;
    }
    long long distributeCandies(int n, int limit) {
        return nCr(n + 2) - 3 * nCr(n - limit + 1) + 3 * nCr(n - (limit + 1) * 2 + 2) - nCr(n - 3 * (limit + 1) + 2);
    }
};