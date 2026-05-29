class Solution {
public:
    int sumOfDigits(int x) {
        int ans = 0;
        while(x) {
            ans += x % 10;
            x /= 10;
        }
        return ans;
    }
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(int x : nums) ans = min(ans, sumOfDigits(x));
        return ans;
    }
};