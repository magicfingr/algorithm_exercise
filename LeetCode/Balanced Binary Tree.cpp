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
    bool isBalanced(TreeNode *root) {
        bool flag = true;
        depth(root, flag);
        return flag;
    }
private:
    //计算其深度，同时判断每个节点是否平衡
    int depth(TreeNode *root, bool &flag){
        if(!root || !flag)
            return 0;
        int left = depth(root->left, flag);
        int right;
        if(flag)
            right = depth(root->right, flag);
        
        if(!flag || abs(left - right) > 1){
            flag = false;
            return 0;
        }
        return max(left, right) + 1;
    }
};