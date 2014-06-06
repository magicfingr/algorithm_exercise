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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> visit;
        stack<TreeNode*> s;
        TreeNode *t = root;
        //循环：栈非空或访问指针非空
        while(!s.empty() || t != NULL){
            //if节点非空
            if(t != NULL){
                //访问当前节点
                visit.push_back(t->val);
                //若存在右子树：保存右子树地址
                if(t->right != NULL)
                    s.push(t->right);
                //向左
                t = t->left;
            } else{
            //else取栈顶元素继续访问，出栈
                t = s.top();
                s.pop();
            }
        }
        return visit;
    }
};
