class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> re;
        if(matrix.size() > 0){
            m_spiral(matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1, re);
        }
        return re;
    }
private:
    void m_spiral(vector<vector<int> > &matrix, const int rowS, const int rowE, const int colS, const int colE, vector<int> &re){
        if(rowS > rowE || colS > colE)
            return;
        for(int i = colS; i <= colE; i++)
            re.push_back(matrix[rowS][i]);
        for(int i = rowS + 1; i <= rowE; i++)
            re.push_back(matrix[i][colE]);
        if(rowS < rowE){
            for(int i = colE - 1; i >= colS; i--)
                re.push_back(matrix[rowE][i]);
        }
        if(colS < colE){
            for(int i = rowE - 1; i >= rowS + 1; i--)
                re.push_back(matrix[i][colS]);
        }
        m_spiral(matrix, rowS + 1, rowE - 1, colS + 1, colE - 1, re);
    }
};