/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /**DFS
     * 注意节点值可为负，所以要一直走到叶子节点以后才能判断
     */
    bool hasPathSum(TreeNode *root, int sum) {
        return findPath(root, sum, 0);
    }
private:
    bool findPath(const TreeNode *root, const int destSum, int curSum){
        if(!root)
            return false;
        curSum += root->val;
        if((!root->left && !root->right) && curSum == destSum)
            return true;
        
        if(findPath(root->left, destSum, curSum))
            return true;
        else
            return findPath(root->right, destSum, curSum);
    }
};
