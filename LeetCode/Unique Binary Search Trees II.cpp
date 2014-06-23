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
     * 递归生成[i, j]的BST
     */
    vector<TreeNode *> generateTrees(int n) {
        return m_generateTrees(1, n);
    }
private:
    vector<TreeNode *> m_generateTrees(int begin, int end){
        vector<TreeNode *> re;
        if(begin > end){
            re.push_back(NULL);
            return re;
        }
        for(int i = begin; i <= end; i++){
            //tree: [begin, i - 1], i, [i + 1, end]
            vector<TreeNode*> leftTrees = m_generateTrees(begin, i - 1);
            vector<TreeNode*> rightTrees = m_generateTrees(i + 1, end);
            //组合根、左、右子树
            for(vector<TreeNode*>::const_iterator leftIt = leftTrees.begin(); leftIt != leftTrees.end(); leftIt++){
                for(vector<TreeNode*>::const_iterator rightIt = rightTrees.begin(); rightIt != rightTrees.end(); rightIt++){
                    TreeNode *root = new TreeNode(i);
                    root->left = *leftIt;
                    root->right = *rightIt;
                    re.push_back(root);
                }
            }
        }
        return re;
    }
};