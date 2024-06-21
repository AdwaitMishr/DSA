class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int unsatisfiedWindow = 0;
        int maxUnsatisfied = 0;
        int satisfied = 0;
        for(int i = 0; i < minutes; i++) {
            unsatisfiedWindow += customers[i] * grumpy[i];
        }
        maxUnsatisfied = unsatisfiedWindow;
        int i = 0;
        int j = minutes;
        while( j < customers.size()) {
            unsatisfiedWindow += customers[j] * grumpy[j];
            unsatisfiedWindow -= customers[i] * grumpy[i];
            maxUnsatisfied = max(maxUnsatisfied,unsatisfiedWindow);
            i++;
            j++;
        }
        for(int k = 0; k < customers.size(); k++) {
            satisfied += customers[k] * (!grumpy[k]);
        }

        return satisfied+maxUnsatisfied;
    }
};