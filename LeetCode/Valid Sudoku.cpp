class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        const int SIZE = 9;
        bool isUsed[10];
        // row
        for(int i = 0; i < SIZE; i++){
            memset(isUsed, false, sizeof(bool) * 10);
            for(int j = 0; j < SIZE; j++){
                if(board[i][j] != '.'){
                    if(isUsed[board[i][j] - '0'])
                        return false;
                    isUsed[board[i][j] - '0'] = true;
                }
            }
        }
        // column
        for(int j = 0; j < SIZE; j++){
            memset(isUsed, false, sizeof(bool) * 10);
            for(int i = 0; i < SIZE; i++){
                if(board[i][j] != '.'){
                    if(isUsed[board[i][j] - '0'])
                        return false;
                    isUsed[board[i][j] - '0'] = true;
                }
            }
        }
        // box
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(!isValidBox(board, i * 3, j * 3))
                    return false;
            }
        }
        return true;
    }
private:
    bool isValidBox(vector<vector<char> > &board, int x, int y){
        bool isUsed[10];
        memset(isUsed, false, sizeof(bool) * 10);
        for(int i = x; i < x + 3; i++){
            for(int j = y; j < y + 3; j++){
                if(board[i][j] != '.'){
                    if(isUsed[board[i][j] - '0'])
                        return false;
                    isUsed[board[i][j] - '0'] = true;
                }
            }
        }
        return true;
    }
};