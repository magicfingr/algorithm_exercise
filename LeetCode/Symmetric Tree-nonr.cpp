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
     * 映射后，对除了根节点外的每个节点来说，它的左右子树互换了位置，据此判断即可
     */
    bool isSymmetric(TreeNode *root) {
        if(!root)
            return true;
        //递归转循环：用栈保存所有将来需要计算值
        bool flag = true;
        stack<TreeNode*> nodes;
        nodes.push(root->left);
        nodes.push(root->right);
        while(!nodes.empty() && flag){
            TreeNode *root = nodes.top();
            nodes.pop();
            TreeNode *mirrorRoot = nodes.top();
            nodes.pop();
            if(root == NULL || mirrorRoot == NULL){
                flag = (root == mirrorRoot);
            } else{
                flag = (root->val == mirrorRoot->val);
                nodes.push(root->left);
                nodes.push(mirrorRoot->right);
                
                nodes.push(root->right);
                nodes.push(mirrorRoot->left);
            }
        }
        return flag;
    }
};