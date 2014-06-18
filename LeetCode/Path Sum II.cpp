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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > paths;
        vector<int> curPath;
        findPath(root, sum, 0, curPath, paths);
        return paths;
    }
private:
    void findPath(const TreeNode* root, const int destSum, int curSum, vector<int> curPath, vector<vector<int> > &paths){
        if(!root) return;
        curSum += root->val;
        curPath.push_back(root->val);
        
        if((!root->left && !root->right) && curSum == destSum){
            paths.push_back(curPath);
            return;
        }
        
        findPath(root->left, destSum, curSum, curPath, paths);
        findPath(root->right, destSum, curSum, curPath, paths);
    }
    /*
    void findPath(const TreeNode* root, const int destSum, int curSum, vector<int> &curPath, vector<vector<int> > &paths){
        if(!root) return;
        curSum += root->val;
        curPath.push_back(root->val);
        
        if((!root->left && !root->right) && curSum == destSum){
            paths.push_back(curPath);
            curPath.pop_back();
            return;
        }
        
        findPath(root->left, destSum, curSum, curPath, paths);
        curPath.pop_back();
        
        curPath.push_back(root->val);
        findPath(root->right, destSum, curSum, curPath, paths);
        curPath.pop_back();
    }
    */
};
