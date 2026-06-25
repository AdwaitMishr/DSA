class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        if(x == 0) return 0;
        if(x == 1.0 || n == 0) return 1;
        int sign = n > 0 ? 1 : -1;
        long long b = (long long)n * sign;
        while(b > 0) {
            if(b & 1) res *= x;
            x *= x;
            b >>= 1;
        }
        if(sign == -1) return 1 / res;
        return res;
    }
};