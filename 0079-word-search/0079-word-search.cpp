class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(dfs(i, j, 0, board, word, visited))
                    return true;
            }
        }
        return false;
    }

    bool dfs(int i, int j, int k, vector<vector<char>>& board, string word, vector<vector<bool>> & visited) {
        if(k == word.size())
            return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[k] || visited[i][j])
            return false;    
    
        visited[i][j] = true;
        bool res = (dfs(i + 1, j, k + 1, board, word, visited)
                ||dfs(i - 1, j, k + 1, board, word, visited)
                ||dfs(i, j + 1, k + 1, board, word, visited)
                ||dfs(i, j - 1, k + 1, board, word, visited));
        visited[i][j] = false;
        return res;
    }   

};