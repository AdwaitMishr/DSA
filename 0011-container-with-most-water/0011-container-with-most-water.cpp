class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxAr = INT_MIN;
        while(i < j) {
            int l = (j - i);
            int area = l * min(height[i], height[j]);
            maxAr = max(maxAr, area);
            if( height[i] < height[j]) i++;
            else j--;

        } 
        return maxAr;
    }
};