class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        string middle = "";
        for(char c: s) freq[c - 'a']++;
        string ans = "";
        for(int i = 0; i < 26; i++) {
            if(freq[i]) {
                int sz = freq[i];
                if(sz & 1) middle = i + 'a';
                string s(sz/2, (char)('a' + i));
                cout << s << " ";
                ans += s;
            }
        }
        string back = ans;
        reverse(back.begin(), back.end());
        ans = ans + middle + back;
        return ans;
    }
};