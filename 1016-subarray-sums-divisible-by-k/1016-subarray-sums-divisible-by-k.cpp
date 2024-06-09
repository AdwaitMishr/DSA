class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> remainderMap;
        remainderMap[0]=1;
        int sum=0;
        int c=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int remainder = sum % k;
            // Adjust the remainder to be positive
            if (remainder < 0) {
                remainder += k;
            }
            c+=remainderMap[remainder];
            remainderMap[remainder]++;
        }
        return c;
    }
};