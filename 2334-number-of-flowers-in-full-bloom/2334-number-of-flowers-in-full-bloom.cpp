class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        multiset<pair<int, int>> sortedPeople;
        int n = flowers.size();
        int m = people.size();
        for(int i = 0; i < n; i++) {
            pq.push({flowers[i][0], 1});
            pq.push({flowers[i][1] + 1, -1});
        }

        for(int i = 0; i < m; i++)
            sortedPeople.insert({people[i], i});
        vector<int> ans(m, 0);
        int flowersBloomed = 0;
        for(auto& [time, idx] : sortedPeople) {
            while(!pq.empty() && time >= pq.top().first) {
                flowersBloomed += pq.top().second;
                pq.pop();
            }
            ans[idx] = flowersBloomed;
        }
        return ans;
    }
};
