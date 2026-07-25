class Solution {
public:
    int maxProduct(int n) {
        int max1 = INT_MIN, max2 = INT_MIN;
        while(n) {
            int x = n % 10;
            if(x > max1 ) {
                max2 = max1;
                max1 = x;
            }else if(x > max2 ) max2 = x;
            n/= 10;
        }
        return (max1 * max2);
    }
};