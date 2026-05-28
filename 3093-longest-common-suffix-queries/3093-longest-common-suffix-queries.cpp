class Solution {
    struct Node {
        int links[26];
        int best;
        Node() {
            fill(begin(links), end(links), -1);
            best = -1;
        }
    };

    vector<Node> trie;

    bool isBetter(int nIdx, int oIdx, vector<string>& wordsContainer) {
        if(oIdx == -1) return true;
        int l1 = wordsContainer[nIdx].size();
        int l2 = wordsContainer[oIdx].size();
        if(l1 < l2) return true;
        else if (l1 == l2 && nIdx < oIdx) return true;
        return false;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
       
        trie.push_back(Node()); 

        for(int i = 0; i < wordsContainer.size(); i++) {
            int curr = 0; 
            string& word = wordsContainer[i];
            
            if(isBetter(i, trie[curr].best, wordsContainer)) trie[curr].best = i;
            
            for(int j = word.size() - 1; j >= 0; j--) {
                int c = word[j] - 'a';
                 if(trie[curr].links[c] == -1) {
                    trie[curr].links[c] = trie.size();
                    trie.push_back(Node());
                }
                
                curr = trie[curr].links[c];
                
                if(isBetter(i, trie[curr].best, wordsContainer)) trie[curr].best = i;
            }
        }
        
        vector<int> ans(wordsQuery.size());
        for(int i = 0; i < wordsQuery.size(); i++) {
            int curr = 0;
            const string& q = wordsQuery[i];
            for(int j = q.size() - 1; j >= 0; j--) {
                int c = q[j] - 'a';
                if(trie[curr].links[c] == -1) break; 
                curr = trie[curr].links[c];
            }
            ans[i] = trie[curr].best;
        }
        
        return ans;
    }
};