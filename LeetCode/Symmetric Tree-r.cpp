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
     * 根节点的左右子树中，每一层的访问序列刚好相反且节点相等（必须一一反向对应）
     * 层次遍历左子树，并将访问序列存到vector+stack里，然后层次访问右子树，并和保存的序列比照，O(N),O(N)
     * 特别注意考虑节点的位置，如{1,2}
     * 算法错误，层次遍历的方法需要保存下所有节点的位置，也就是说要填充所有空节点
     * 实际上树映射后，对除了根节点外的每个节点来说，它的左右子树互换了位置，据此判断即可
     */
    bool isSymmetric(TreeNode *root) {
        if(!root)
            return true;
        return isMirrored(root->left, root->right);
    }
private:
    bool isMirrored(TreeNode *root, TreeNode *mirrorRoot){
        if(root == NULL || mirrorRoot == NULL)
            return root == mirrorRoot;
        if(root->val != mirrorRoot->val)
            return false;

        return isMirrored(root->left, mirrorRoot->right) && isMirrored(root->right, mirrorRoot->left);
    }
};