class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > triangle;
        if(numRows <= 0)
            return triangle;
        vector<int> newRow;
        newRow.push_back(1);
        triangle.push_back(newRow);
        for(int irow = 1; irow < numRows; irow++){
            newRow.clear();
            newRow.push_back(1);
            vector<int> lastRow = triangle[triangle.size() - 1];
            for(int i = 0; i < lastRow.size() - 1; i++){
                newRow.push_back(lastRow[i] + lastRow[i + 1]);
            }
            newRow.push_back(1);
            triangle.push_back(newRow);
        }
        return triangle;
    }
};