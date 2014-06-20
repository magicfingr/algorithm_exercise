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
    int maxDepth(TreeNode *root) {
        return depth(root);
    }
private:
    int depth(TreeNode *root){
        if(!root)
            return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
};