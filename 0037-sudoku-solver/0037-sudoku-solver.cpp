class Solution {
public:
    bool solveSud(vector<vector<char>>& board, int r, int c,
              vector<vector<int>>& row, vector<vector<int>>& col, vector<vector<int>>& box)
 {
        if(r == 9)
            return true;
        else if(c == 9) return solveSud(board,r+1,0,row,col,box);
        
        else if(board[r][c] != '.')
            return solveSud(board,r,c+1,row,col,box);

          for(char i = '1'; i <= '9'; i++) {
            int num = i - '0';
            if(!row[r][num] && !col[c][num] && !box[(r/3)*3+c/3][num]) {
                row[r][num] = col[c][num] = box[(r/3)*3+c/3][num] = 1;
            board[r][c] = i;
            if(solveSud(board,r,c+1,row,col,box))
                return true;
            board[r][c] = '.';    
                row[r][num] = col[c][num] = box[(r/3)*3+c/3][num] = 0;
        }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9,vector<int>(10,0));
        vector<vector<int>> col(9,vector<int>(10,0));
        vector<vector<int>> box(9,vector<int>(10,0));
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.')
                    continue;
                int digit = board[i][j]- '0';
                int boxIndex = (i / 3)*3 + j / 3;
                row[i][digit] = 1;
                col[j][digit] = 1;
                box[boxIndex][digit] = 1;
            }
        }
         solveSud(board,0,0,row,col,box);
    }
};

                                                                       