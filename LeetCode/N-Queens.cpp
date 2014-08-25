struct MyPoint{
    int x;
    int y;
    MyPoint(int x, int y) : x(x), y(y) {}
};

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> re;
        vector<MyPoint> queens;
        solve(n, queens, re);
        return re;
    }
private:
    void solve(const int n, vector<MyPoint> &queens, vector<vector<string>> &re){
        if (queens.size() == n){
            string s = string(n, '.');
            vector<string> board = vector<string>(n, s);
            for (int i = 0; i < queens.size(); i++){
                board[queens[i].x][queens[i].y] = 'Q';
            }
            re.push_back(board);
            return;
        }
        int row = queens.size();
        for (int col = 0; col < n; col++){
            if (isValid(row, col, queens)){
                queens.push_back(MyPoint(row, col));
                solve(n, queens, re);
                queens.pop_back();
            }
        }
    }
    bool isValid(const int x, const int y, vector<MyPoint> &queens){
        for (int i = 0; i < queens.size(); i++){
            double k = (double)(y - queens[i].y) / (double)(x - queens[i].x);
            //          if (y == queens[i].y || 
            //              ((y - queens[i].y) == (x - queens[i].x)) ||
            //              ((y - queens[i].y) == ( queens[i].x) - x)
            //              )
            if (y == queens[i].y || abs((abs(k) - 1.0)) < 0.0001)
                return false;
        }
        return true;
    }
};