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
     * 中序遍历得到的必须是严格升序序列（貌似不允许重复）
     */
    bool isValidBST(TreeNode *root) {
        vector<int> travel;
        inorderTravel(root, travel);
        if(travel.size() <= 0)
            return true;
        bool isValid = true;
        for(int i = 1; i < travel.size(); i++){
            if(travel[i] <= travel[i - 1]){
                isValid = false;
                break;
            }
        }
        return isValid;
    }
private:
    void inorderTravel(TreeNode *root, vector<int> &travel){
        if(root){
            inorderTravel(root->left, travel);
            travel.push_back(root->val);
            inorderTravel(root->right, travel);
        }
    }
};