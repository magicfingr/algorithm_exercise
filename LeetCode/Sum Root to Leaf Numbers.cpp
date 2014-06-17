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
    int sumNumbers(TreeNode *root) {
        //先序遍历即可，走到叶子节点以后累加number
        int sum = 0;
        int number = 0;
        preOrder(root, number, sum);
        return sum;
    }
    
    void preOrder(TreeNode *root, int number, int &sum){
        if(root != NULL){
            number = number * 10 + root->val;
            if(!root->left && !root->right){
                sum += number;
                return;
            }
            preOrder(root->left, number, sum);
            preOrder(root->right, number, sum);
        }
    }
};