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
    //类似Convert Sorted List to Binary Search Tree，不过更简单
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.size() <= 0)
            return NULL;
        TreeNode *root = NULL;
        vector<int> left;
        vector<int> right;
        int mid;
        if(slice(num, left, right, mid)){
            root = new TreeNode(mid);
            root->left = sortedArrayToBST(left);
            root->right = sortedArrayToBST(right);
        }
        return root;
    }
private:
    //将vector切成左右两部分以及单独的中点，返回值表示是否切割成功（三段中至少有一段有效，即存在原vector中至少有一个点）
    bool slice(const vector<int> &origin, vector<int> &left, vector<int> &right, int &mid){
        if(origin.size() <= 0)
            return false;
        //cut: [0, midPos - 1], midPos, [midPos + 1, origin.size() - 1]
        int midPos = origin.size() / 2;
        mid = origin[midPos];
        
        int leftSize = midPos;
        int rightSize = origin.size() - midPos - 1;
        vector<int>::const_iterator it = origin.begin();
        if(leftSize > 0)
            left = vector<int>(origin.begin(), origin.begin() + leftSize);
        if(rightSize > 0)
            right = vector<int>(origin.begin() + midPos + 1, origin.end());
        return true;
    }
};