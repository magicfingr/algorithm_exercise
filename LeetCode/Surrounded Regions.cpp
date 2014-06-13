class Solution {
public:
    /**
     * 只有边界上的O不能被capture，dfs标记这些O，其他的最后都是X
     * 注意直接dfs会RE，应该是栈溢出，需要用非递归的dfs
     * 注意board是矩形，不一定是正方形！
     * O(N^2),O(N)
     */
    void solve(vector<vector<char>> &board) {
        //找所有边界上的O并标记为V
        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[row].size(); col++){
                if(row == 0 || row == board.size() - 1 || col == 0 || col == board[row].size() - 1)
                    dfs(row, col, board);
            }
        }
        //除V以外都被capture为X，V改回O
        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[row].size(); col++){
                if(board[row][col] == 'V')
                    board[row][col] = 'O';
                else
                    board[row][col] = 'X';
            }
        }
    }
private:
    //dfs，从当前点出发，标记所有相邻的O点
    void dfs(const int startRow, const int startCol, vector<vector<char>> &board){
        struct Point{
            int row;
            int col;
            Point(int row, int col): row(row), col(col){}
        };
        stack<Point> sta;
        sta.push(Point(startRow, startCol));
        while(!sta.empty()){
            Point p = sta.top();
            sta.pop();
            if(p.row < 0 || p.row >= board.size() || p.col < 0 || p.col >= board[p.row].size()){
                continue;
            }
            if(board[p.row][p.col] == 'O'){
                board[p.row][p.col] = 'V';
                sta.push(Point(p.row - 1, p.col));
                sta.push(Point(p.row + 1, p.col));
                sta.push(Point(p.row, p.col - 1));
                sta.push(Point(p.row, p.col + 1));
            }
        }
    }
};