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
     * 通过先序找到根节点，然后递归对左右两边剩余的数组调用函数即可
     * 未处理非法输入
     */
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size() <= 0)
            return NULL;
        else
            return m_buildTree(&preorder[0], &inorder[0], preorder.size());
    }
private:
    TreeNode *m_buildTree(int* preorder, int* inorder, int size) {
        if(size <= 0)
            return NULL;
        TreeNode *root = new TreeNode(preorder[0]);
        int index = -1;
        for(int i = 0; i < size; i++){
            if(preorder[0] == inorder[i]){
                index = i;
                break;
            }
        }
        //preorder: 0, [1, index], [index + 1, size - 1]
        //inorder:  [0, index - 1], index, [index + 1, size - 1]
        root->left = m_buildTree(preorder + 1, inorder, index);
        root->right = m_buildTree(preorder + index + 1, inorder + index + 1, size - index - 1);
        return root;
    }
};