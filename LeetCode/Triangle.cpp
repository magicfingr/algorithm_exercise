class Solution {
public:
    /**
     * 类似二叉树，自底向上找，用较小的子节点往上加，加到根就是最小path sum
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<int> curResult(triangle[triangle.size() - 1]);   //保存每一层选择的结果
        for(int irow = triangle.size() - 1; irow >= 1; irow--){
            for(int icol = 0; icol < triangle[irow].size() - 1; icol++){
                int rootVal = triangle[irow - 1][icol];
                int leftPathVal = curResult[icol];
                int rightPathVal = curResult[icol + 1];
                
                curResult[icol] = min(leftPathVal, rightPathVal) + rootVal;
                //curResult[icol] = min(curResult[icol], curResult[icol + 1]) + triangle[irow - 1][icol];
            }
        }
        return curResult[0];
    }
};