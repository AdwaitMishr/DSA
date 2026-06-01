class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        long long sum = cost[0];
        for(int i = 1; i < cost.size(); i++) {
            if(!((i + 1) % 3)) continue;
            else sum += cost[i];
        }
        return sum;
    }
};