class Solution {
public:
    int dfs(int box, unordered_set<int>& seen, unordered_set<int>& canLook, vector<int>& status, vector<int>& candies, vector<vector<int>>& containedBoxes, vector<vector<int>>& keys) {
        if(seen.count(box)) return 0;

        if(status[box] == 0) {
            canLook.insert(box);
             return 0;
             }
        seen.insert(box);
        int total = candies[box];

        for(int nxt : containedBoxes[box]) {
            total += dfs(nxt, seen, canLook, status, candies, containedBoxes, keys);
        }     
        for(int key : keys[box]) {
            status[key] = 1;
            if(canLook.count(key)) total += dfs(key, seen, canLook, status, candies, containedBoxes, keys);

        }
        return total;
    }
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        unordered_set<int> seen;
        unordered_set<int> canLook;
        int ans = 0;
        for(int box : initialBoxes) ans += dfs(box, seen, canLook, status, candies, containedBoxes, keys);
        return ans;
    }
};