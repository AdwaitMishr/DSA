class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int n = costs.size();
        int ans = 0;
        for(int x : costs) {
            if(coins < x) break;
            coins -= x;
            ans++;
        }
        return ans;
    }
};