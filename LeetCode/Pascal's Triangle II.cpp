class Solution {
public:
    /**
     * 注意这题的行标号是从0开始的
     */
    vector<int> getRow(int rowIndex) {
        vector<int> oldRow;
        if(rowIndex < 0)
            return oldRow;
        oldRow.push_back(1);
        for(int irow = 0; irow < rowIndex; irow++){
            vector<int> newRow;
            newRow.push_back(1);
            for(int i = 0; i < oldRow.size() - 1; i++){
                newRow.push_back(oldRow[i] + oldRow[i + 1]);
            }
            newRow.push_back(1);
            oldRow.swap(newRow);
        }
        return oldRow;
    }
};