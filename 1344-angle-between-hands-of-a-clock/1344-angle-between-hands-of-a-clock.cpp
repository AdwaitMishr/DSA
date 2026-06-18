class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans = abs((hour * 30 + minutes * 0.5) - (minutes * 6));
        return min(ans, 360 - ans);
    }
};