class Solution {
public:
    int maxDiff(int num) {
        string maxCopy = to_string(num);
        string minCopy = to_string(num);
        char toMaxNum;
        for(int i = 0; i < maxCopy.length(); i++) {
            if(maxCopy[i] == '9') continue;
            else {
                toMaxNum = maxCopy[i];
                break;
            }
        }   
        char toMinNum;
        for(int i = 0; i < minCopy.length(); i++) {
            if(minCopy[i] == '0' || (i == 0 && minCopy[i] == '1') ) continue;
            else {
                if(minCopy[i] == '1') continue;
                else {
                toMinNum = minCopy[i];
                break;   
                }
            }
        }
        char mini = toMinNum == minCopy[0] ? '1' : '0';
        for(int i = 0; i < maxCopy.length(); i++) {
            if(maxCopy[i] == toMaxNum) maxCopy[i] = '9'; 
        }
        for(int i = 0; i < minCopy.length(); i++) {
            if(minCopy[i] == toMinNum) minCopy[i] = mini; 
        }
        return stoi(maxCopy) - stoi(minCopy);
    }
};