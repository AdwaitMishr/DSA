class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);
        vector<bool> visA(n + 1, false), visB(n + 1, false);
        for(int i = 0; i < n; i++) {
            if(!i) {
                if(A[i] == B[i]) ans[i] = 1;
                visA[A[i]] = true;
                visB[B[i]] = true;
            } else {
                if(A[i] == B[i]) ans[i] = 1 + ans[i - 1];
                else {
                    int matches = 0;
                    if(visA[B[i]]) matches++;
                    if(visB[A[i]]) matches++;
                    ans[i] = ans[i - 1] + matches;
                }
                visA[A[i]] = true;
                visB[B[i]] = true;
            }
        }
        return ans;
    }
};