class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(begin(asteroids), end(asteroids));
        if(mass < asteroids[0]) return false;
        long long temp = mass;
        for(int i = 1; i < size(asteroids); i++) {
            if(temp + asteroids[i - 1] < asteroids[i]) return false;
            else temp += asteroids[i - 1];
        }
        return true;
    }
};