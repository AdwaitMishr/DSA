class Solution {
public:
    int appendCharacters(string s, string t) {
        int res=t.length();
        int i=0,j=0;
        while(i<s.length() && j<t.length()){
            if(s[i]==t[j]){
                i++;
                res--;
                j++;
                continue;
            }
            i++;
        }
        return res;
    }
};