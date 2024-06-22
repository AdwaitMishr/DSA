class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int j = 0, odd = 0, count = 0, total = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & 1) { //1 -> odd (true) & 0 -> even (false)
                odd++;
                if (odd >= k) {
                    count = 1;
                    while (!(nums[j++] & 1)) count++; //1 -> odd (false) & 0 -> even (true)
                    total += count;
                }
            } else if (odd >= k) total += count;
        }
        return total;
    }
};