/*
测试：
1,2
1,2,3
3,1,2
2,3,1
4,5,6,1,3,2
*/
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
	* 最简单的当然是递归中序遍历，并且保存访问序列，然后找出位置不对的两点（按题意有且只有两点），交换节点值。O(N),O(N)
	* Morris Traversal:
	* 基于线索二叉树的思想，为每个节点保存下访问序列的后继节点。
	* 在中序遍历中，当前节点是左子树最大节点的后继，可以直接将当前节点的位置临时存在其前驱的right域中，即可不需stack实现中序遍历。
	* 在从前驱返回到当前节点之后（线索已使用），即可将前驱节点的right域复原（NULL）。O(NlogN)?, O(1)
	*/
	void recoverTree(TreeNode *root) {
		//assert: 树的节点数必须大于等于2
		TreeNode *firstWrong = NULL;
		TreeNode *secondWrong = NULL;
		TreeNode *cur = root;
		TreeNode *pre = NULL;
		while(cur != NULL){
		    //如果有左子树，若第一次到达此节点，则构造线索，否则还原
		    if(cur->left){
		        //找左子树最右节点
		        TreeNode *leftMax = cur->left;
		        while(leftMax->right != NULL && leftMax->right != cur){
		            leftMax = leftMax->right;
		        }
		        //若左子树最右节点的right域为NULL，则构造线索，并继续往左
		        if(leftMax->right == NULL){
		            leftMax->right = cur;
		            cur = cur->left;
		        }
		        //若左子树最右节点的right域为当前节点，表示线索已使用，则还原树，访问当前节点，并继续往右
		        else{
		            visit(pre, cur, firstWrong, secondWrong);
		            pre = cur;
		            
		            leftMax->right = NULL;
		            cur = cur->right;
		        }
		    }
		    //若没有左子树，则访问当前节点，然后往右（此时已经加入了线索）
		    else{
	            visit(pre, cur, firstWrong, secondWrong);
	            pre = cur;
	            
		        cur = cur->right;
		    }
		}
		//交换两个错误节点的值
		int oldSecondVal = secondWrong->val;
		secondWrong->val = firstWrong->val;
		firstWrong->val = oldSecondVal;
	}
private:
    /**
     * 访问cur节点，并用它的前驱节点判断其位置是否正确
     * 更新错误位置时注意重复访问的情况
     */
    void visit(TreeNode *pre, TreeNode *cur, TreeNode* &firstWrong, TreeNode* &secondWrong){
        if(pre == NULL || cur == NULL)
            return;
        if(pre->val >= cur->val){
            if(firstWrong == NULL){     //找到第一对位置错误的节点
                firstWrong = pre;
                secondWrong = cur;
            } else if(firstWrong != pre) {     //找到第二对位置错误的节点，说明交换的节点位置不相邻
                secondWrong = cur;
                //break;  //不可能有三个位置错误，故至此可结束循环
            }
        }
    }
};