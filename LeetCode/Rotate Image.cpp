class Solution {
public:
    // (i, j) => (j, n - 1 - i) => (n - 1 - i, n - 1 - j) => (n - 1 - j, i) => (i, j)
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int loopRow = n / 2;
        int loopCol = n / 2;
        if(n % 2 != 0)
            loopRow++;
        for(int i = 0; i < loopRow; i++){
            for(int j = 0; j < loopCol; j++){
                int t = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = t;
            }
        }
    }
};