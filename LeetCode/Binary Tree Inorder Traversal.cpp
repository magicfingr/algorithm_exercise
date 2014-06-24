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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> travel;
        stack<TreeNode*> nodes;
        TreeNode *cur = root;
        //先往左走到底，到NULL了就回到先前保存的点，访问并右移
        while(!nodes.empty() || cur != NULL){
            if(cur != NULL){
                nodes.push(cur);
                cur = cur->left;
            } else{
                cur = nodes.top();
                nodes.pop();
                travel.push_back(cur->val);
                cur = cur->right;
            }
        }
        return travel;
    }
};