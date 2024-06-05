class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        vector<int> common(26,INT_MAX);
        for(int i=0;i<words.size();i++){
            vector<int> hash(26,0);
            for(int j=0;j<words[i].length();j++){
                hash[words[i][j]-'a']++;
            }
            for(int k=0;k<26;k++){
                common[k]=min(common[k],hash[k]);
              
            }
        }
        for (int i = 0; i < 26; ++i)
    for (int j = 0; j < common[i]; ++j) ans.push_back(string(1, i + 'a'));

        return ans;
    }
};