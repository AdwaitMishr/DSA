class Solution {
public:
    int furthestDistanceFromOrigin(string m) {
        int l = 0,r = 0,b = 0;
        for(auto s : m) if(s == 'L') l++; else if(s == 'R') r++; else b++;
        return abs(r - l) + b;
    }
};