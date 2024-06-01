class Solution {
public:
    int scoreOfString(string s) {
        int ans=0;
        for(int i=1;i<s.size();i++){
                int temp=((s[i]-s[i-1])>0)?(s[i]-s[i-1]):-(s[i]-s[i-1]);
                ans+=temp;
                }
        return ans;
    }
};