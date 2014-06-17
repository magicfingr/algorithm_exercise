/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * 若按层次遍历，需要O(N)的空间
     * 可利用已赋值的next域模拟层次遍历，访问时只需要保存上一层的第一个节点（父节点），以及本层的第一个节点即可，O(N),O(1)
     * 注意必须是完全二叉树
     */
    void connect(TreeLinkNode *root) {
        TreeLinkNode *upperFirstNode = NULL;    //上层第一个节点
        TreeLinkNode *curFirstNode = root;    //本层第一个节点
        //通过当前节点的父节点以及next域从左往右访问本层节点
        //循环访问所有层
        while(curFirstNode != NULL){
            //访问并赋值一层节点
            visitLevel(upperFirstNode, curFirstNode);
            //移动到下一层
            upperFirstNode = curFirstNode;
            curFirstNode = curFirstNode->left;
        }
    }
private:
    //访问并赋值一层节点
    void visitLevel(TreeLinkNode *upperFirstNode, TreeLinkNode *curFirstNode){
        TreeLinkNode *upperCurNode = upperFirstNode;
        TreeLinkNode *curNode = curFirstNode;
        while(upperCurNode != NULL){
            if(curNode == upperCurNode->left){
                curNode->next = upperCurNode->right;
                upperCurNode = upperCurNode->next;
            } else{
                curNode->next = upperCurNode->left;
            }
            curNode = curNode->next;
        }
        curNode->next = NULL;
    }
};
