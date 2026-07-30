class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int key = n >> 3;
        return (key * (key + 1) * 4) + (n % 8) * (key + 1);
    }
};