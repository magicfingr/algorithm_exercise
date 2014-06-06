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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> visit;
        TreeNode *t = root;
        TreeNode *recent = NULL;
        stack<TreeNode*> s;
        //循环
        while(!s.empty() || t != NULL){
            //如果节点非空（有左子树）
            if(t != NULL){
                s.push(t);
                t = t->left;
            } else{
            //节点为空，表示已经访问完当前子树，可以继续访问栈中保存的其他树
                //取栈顶保存的元素
                t = s.top();
                //如果有右子树，且没有访问过右
                if(t->right != NULL && t->right != recent){
                    //向右，继续循环
                    t = t->right;
                } else{
                //右子树已经访问
                    visit.push_back(t->val);
                    recent = t;
                    s.pop();
                    //用NULL向上返回，表示此子树已经访问完，可以访问栈中保存的其他树
                    t = NULL;
                }
            }
        }
        return visit;
    }
};
