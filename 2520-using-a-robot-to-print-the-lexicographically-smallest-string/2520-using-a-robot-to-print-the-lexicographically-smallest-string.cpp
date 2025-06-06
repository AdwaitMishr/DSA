class Solution {
public:
    string robotWithString(string s) {
        unordered_map<char, int> hash;
        for(auto& c : s) hash[c]++;

        stack<char> st;
        string res = "";
        char smallChar = 'a';
        for(auto& c : s) {
            st.push(c);
            hash[c]--;
            while(smallChar != 'z' && hash[smallChar] == 0)
                smallChar++;
            while(!st.empty() && st.top() <= smallChar) {
                res += st.top();
                st.pop();
            }    
        }
        return res;
    }
};