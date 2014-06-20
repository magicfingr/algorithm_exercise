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
     * 普通层次遍历，先把结果存到stack里，再弹出到vector里,O(N*logN),O(N)
     */
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        stack<vector<int> > stackRe;
        if(!root)
            return result;
        vector<int> level;
        queue<TreeNode*> visit;
        visit.push(root);
        visit.push(NULL);
        while(!visit.empty()){
            TreeNode *cur = visit.front();
            visit.pop();
            if(cur != NULL){
                level.push_back(cur->val);
                if(cur->left)
                    visit.push(cur->left);
                if(cur->right)
                    visit.push(cur->right);
            }
            else{
                stackRe.push(level);
                level.clear();
                if(visit.empty())
                    break;
                visit.push(NULL);
            }
        }
        while(!stackRe.empty()){
            result.push_back(stackRe.top());
            stackRe.pop();
        }
        return result;
    }
};