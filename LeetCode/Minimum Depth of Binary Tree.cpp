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
     * 层次遍历
     */
    int minDepth(TreeNode *root) {
        if(!root)
            return 0;
        queue<TreeNode*> visit;
        visit.push(root);
        visit.push(NULL);   //层结束标志
        int level = 1;
        while(!visit.empty()){
            TreeNode *cur = visit.front();
            visit.pop();
            if(!cur){   //一层访问完毕
                visit.push(NULL);
                level++;
                continue;
                /*
                if(visit.empty())
                    break;
                cur = visit.front();
                visit.pop();
                */
            }
            if(!cur->left && !cur->right)
                return level;
            if(cur->left)
                visit.push(cur->left);
            if(cur->right)
                visit.push(cur->right);
        }
        //一定会遍历结束前，即在while中返回
        return 0;
    }
};