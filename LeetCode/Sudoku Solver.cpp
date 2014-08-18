class Solution {
public:
    // dfs
    void solveSudoku(vector<vector<char> > &board) {
        solve(board);
    }
private:
    bool solve(vector<vector<char> > &board){
        const int SIZE = 9;
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                // found an empty cell
                if(board[i][j] == '.'){
                    // try from 1~9
                    for(char c = '1'; c <= '9'; c++){
                        board[i][j] = c;
                        if(isValidSudoku(board, i, j) && solve(board))
                            return true;
                        // rollback
                        board[i][j] = '.';
                    }
                    // all tries failed, current sudoku unsolvable
                    return false;
                }
            }
        }
        // no more empty cell
        return true;
    }
    
    bool isValidSudoku(vector<vector<char> > &board, int x, int y){
        const int SIZE = 9;
        // row
        for(int i = 0; i < SIZE; i++){
            if((i != y) && board[x][i] == board[x][y])
                return false;
        }
        // column
        for(int i = 0; i < SIZE; i++){
            if((i != x) && board[i][y] == board[x][y])
                return false;
        }
        // box
        int startX = (x / 3) * 3;
        int startY = (y / 3) * 3;
        for(int i = startX; i < startX + 3; i++){
            for(int j = startY; j < startY + 3; j++){
                if(((i != x) || (j != y)) && board[i][j] == board[x][y])
                    return false;
            }
        }
        return true;
    }
};