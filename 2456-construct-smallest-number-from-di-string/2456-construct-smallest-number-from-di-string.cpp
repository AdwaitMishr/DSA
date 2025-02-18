class Solution {
public:
    bool found = false;
    
    bool validate(string possibleAnswer, string pattern) {
        int n = pattern.length();
        for (int i = 0; i < n; i++) {
            if (pattern[i] == 'I') {
                if (possibleAnswer[i] > possibleAnswer[i + 1])
                    return false;
            }
            else { 
                if (possibleAnswer[i] < possibleAnswer[i + 1])
                    return false;
            }
        }
        return true;
    }
    
    void generatePermutation(string &possibleAnswer, int l, int r, string &actualAnswer,  string &pattern) {
        if (l == r) {
            if (validate(possibleAnswer, pattern) && !found) {
                actualAnswer = possibleAnswer;
                found = true; 
            }
            return;
        }
        for (int i = l; i <= r && !found; i++) {
            swap(possibleAnswer[l], possibleAnswer[i]);
            generatePermutation(possibleAnswer, l + 1, r, actualAnswer, pattern);
            swap(possibleAnswer[l], possibleAnswer[i]);
        }
    }
    
    string smallestNumber(string pattern) {
        int n = pattern.length();
        string possibleAnswer = "";
 
        for (int i = 1; i <= n + 1; i++) {
            possibleAnswer += (i + '0');
        }
        string actualAnswer = "";
        generatePermutation(possibleAnswer, 0, n, actualAnswer, pattern);
        return actualAnswer;
    } 
};
