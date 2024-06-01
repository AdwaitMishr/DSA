class Solution {
public:
    void res(vector<string> &ans,string temp,int i,string map[],string digits){
        if(i>=digits.length()){
            return ans.push_back(temp);
            return ;
        }
        int num=digits[i]-'0';
        string mpd=map[num];
        for(int j=0;j<mpd.length();j++){
            temp+=mpd[j];
            res(ans,temp,i+1,map,digits);
            temp.pop_back();
        }
        

    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        string temp;
        int i=0;
        string map[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        res(ans,temp,i,map,digits);
        return ans;
    } 
};