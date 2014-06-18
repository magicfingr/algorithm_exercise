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
     * 非递归先序遍历，当前节点的right指针指向下一个节点
     * 注意展开之后要将树的左子树置为NULL
     */
    void flatten(TreeNode *root) {
        stack<TreeNode*> visit;
        if(root)
            visit.push(root);
        while(!visit.empty()){
            TreeNode *cur = visit.top();
            visit.pop();
            if(cur->right)
                visit.push(cur->right);
            if(cur->left)
                visit.push(cur->left);
            cur->left = NULL;
            if(!visit.empty())
                cur->right = visit.top();
        }
    }
};
