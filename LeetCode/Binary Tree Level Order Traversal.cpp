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
     * 按照一般的层次遍历算法，visit动作为加入到结果集
     */
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if(!root)
            return result;
        queue<TreeNode*> visit;
        visit.push(root);
        visit.push(NULL);   //level tag
        vector<int> level;
        while(!visit.empty()){
            TreeNode *cur = visit.front();
            visit.pop();
            if(cur == NULL){
                result.push_back(level);
                level.clear();
                
                if(visit.empty())   //no more levels
                    break;
                visit.push(NULL);
            } else{
                level.push_back(cur->val);
                if(cur->left)
                    visit.push(cur->left);
                if(cur->right)
                    visit.push(cur->right);
            }
        }
        return result;
    }
};