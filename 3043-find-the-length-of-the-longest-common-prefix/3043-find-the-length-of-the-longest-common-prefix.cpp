class Node{
public:
    Node* links[10];
    bool flag = false;
    Node() {
        for(int i = 0; i < 10; i++) links[i] = nullptr;
    }
};

class Trie{
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(int num) {
        Node* node = root;
        string s = to_string(num);
        for(char c : s) {
            int idx = c - '0';
            if(!node -> links[idx]) {
                node -> links[idx] = new Node();
            }
            node = node -> links[idx];
        }
    }
    int find(int num) {
        Node* n = root;
        int len = 0;
        string s = to_string(num);
        for(char c : s) {
            int idx = c - '0';
            if(n -> links[idx] ) {
                len++;
                n = n -> links[idx];
            }
            else break;
        }
        return len;
    } 
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie t;
        for(int n : arr1) {
            t.insert(n);
        }
        int ans = 0;
        for(int num : arr2) {
            int len = t.find(num);
            ans = max(ans, len);
        }
        return ans;
    }
};