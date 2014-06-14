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
    /**
     * 一开始题目理解错了，以为是要算所有path数量
     * 
     * 对某节点来说，最大的路径和要么出现在其左右子树中，要么从左子树经过根到右子树。
     * 后序遍历，累加从左右子树往上的最大路径，判断经过当前节点能否产生新的最大值；同时随时更新最大路径和
     * 注意path节点的值可能为负，负数的节点不能加入路径（注意全部为负的情况）
     */
    int maxPathSum(TreeNode *root) {
        int maxPathSum = INT_MIN;
        pathSum(root, maxPathSum);
        return maxPathSum;
    }
    
    //计算从叶子节点到root的最大路径和，返回值大于等于0
    int pathSum(TreeNode *root, int &maxPathSum){
        int curSum = 0;
        if(root){
            //计算左子树从叶子节点往上的和
            int leftSum = pathSum(root->left, maxPathSum);
            //计算右子树从叶子节点往上的和
            int rightSum = pathSum(root->right, maxPathSum);
            //判断若经过根节点是否能产生新的最大值
            int newPathSum = leftSum + rightSum + root->val;
            if(maxPathSum < newPathSum)
                maxPathSum = newPathSum;
            //取左右子树和的最大值，加上根节点值返回往上的路径和
            curSum = root->val + max(leftSum, rightSum);
            //若路径和为负，则不加入路径中
            curSum = max(0, curSum);
        }
        return curSum;
    }
};