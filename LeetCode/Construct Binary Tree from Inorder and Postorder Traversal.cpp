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
     * 同先序+中序类似
     */
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() <= 0)
            return NULL;
        else
            return m_buildTree(&inorder[0], &postorder[0], inorder.size());
    }
private:
    TreeNode *m_buildTree(int* inorder, int* postorder, int size) {
        if(size <= 0)
            return NULL;
        TreeNode *root = new TreeNode(postorder[size - 1]);
        //find root node index in inorder traversal
        int index = -1;
        for(int i = 0; i < size; i++){
            if(inorder[i] == postorder[size - 1]){
                index = i;
                break;
            }
        }
        //inorder:   [0, index - 1], index, [index + 1, size - 1]
        //postorder: [0, index - 1], [index, size - 2], size - 1
        root->left = m_buildTree(inorder, postorder, index);
        root->right = m_buildTree(inorder + index + 1, postorder + index, size - index - 1);
        return root;
    }
};