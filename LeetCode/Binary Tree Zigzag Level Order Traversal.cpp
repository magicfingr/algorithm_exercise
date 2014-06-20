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
     * 注意要求每一层的访问顺序不同
     * 最简单的方法是直接反转需要反向访问的层，时间复杂度为O(N^2)
     * 用俩stack交替遍历即可，O(N)
     * PS: 原来的queue实现层次遍历，也可以理解为用俩vector交替遍历
     */
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if(!root)
            return result;
        stack<TreeNode*> visit;     //current level
        stack<TreeNode*> nextVisit; //next level
        visit.push(root);
        bool orderL2R = true;  //level order
        vector<int> level;
        while(!visit.empty()){
            TreeNode *cur = visit.top();
            visit.pop();
            //visiting cur level
            level.push_back(cur->val);
            if(orderL2R){
                if(cur->left)
                    nextVisit.push(cur->left);
                if(cur->right)
                    nextVisit.push(cur->right);
            } else{
                if(cur->right)
                    nextVisit.push(cur->right);
                if(cur->left)
                    nextVisit.push(cur->left);
            }
            //check if current level is done
            if(visit.empty()){
                result.push_back(level);
                level.clear();
                visit.swap(nextVisit);
                orderL2R = (!orderL2R);
            }
        }
        return result;
    }
};