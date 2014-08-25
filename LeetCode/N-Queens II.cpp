struct MyPoint{
    int x;
    int y;
    MyPoint(int x, int y) : x(x), y(y) {}
};

class Solution {
public:
    int totalNQueens(int n) {
        vector<MyPoint> queens;
        int count = 0;
        solve(n, queens, count);
        return count;
    }
private:
    void solve(const int n, vector<MyPoint> &queens, int &count){
        if(queens.size() == n){
            count++;
            return;
        }
        int row = queens.size();
        for(int col = 0; col < n; col++){
            if(isValid(row, col, queens)){
                queens.push_back(MyPoint(row, col));
                solve(n, queens, count);
                queens.pop_back();
            }
        }
    }
    
    bool isValid(const int x, const int y, vector<MyPoint> &queens){
        for(int i = 0; i < queens.size(); i++){
            double k = (double) (y - queens[i].y) / (double) (x - queens[i].x);
            if(y == queens[i].y || abs(abs(k) - 1.0) < 0.0001)
                return false;
        }
        return true;
    }
};