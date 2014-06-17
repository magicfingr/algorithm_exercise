/*
test cases:
1,2
1,#,2
1,2,3,4,#,#,5
3,9,20,#,#,15,7
0,2,4,1,#,3,-1,5,1,#,6,#,8
1,2,3,4,5,#,6,7,#,#,#,#,8
*/
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
     * 类似Populating Next Right Pointers in Each Node，但有非！常！多！的情况要判断
     * PS:网上有实现得更优雅的算法，思路相似，不过不是从当前层往上看，而是从当前层往下看，更新下一层的next域，可以省去很多判断！
     */
    void connect(TreeLinkNode *root) {
        TreeLinkNode *upperFirstNode = NULL;
        TreeLinkNode *curFirstNode = root;
        //循环访问所有层
        while(curFirstNode != NULL){
            //访问某一层同时修改next域
            visitLevel(upperFirstNode, curFirstNode);
            //寻找下一层中第一个非空节点
            TreeLinkNode *cur = NULL;
            while(curFirstNode && !cur){
                if(curFirstNode->left)
                    cur = curFirstNode->left;
                else if(curFirstNode->right)
                    cur = curFirstNode->right;
                else
                    curFirstNode = curFirstNode->next;
            }
            //移动到下一层
            upperFirstNode = curFirstNode;
            curFirstNode = cur;
        }
    }
private:
    //访问某一层同时修改next域
    void visitLevel(TreeLinkNode *upperFirstNode, TreeLinkNode *curFirstNode){
        TreeLinkNode *upperCurNode = upperFirstNode;
        TreeLinkNode *curNode = curFirstNode;
        while(upperCurNode != NULL){
            //若当前节点是上层节点的左子树，则next可能是其右子树，否则是下一个上层节点的左/右子树
            if(curNode == upperCurNode->left){
                if(upperCurNode->right){
                    curNode->next = upperCurNode->right;
                    upperCurNode = upperCurNode->next;
                    curNode = curNode->next;
                    continue;
                } else
                    upperCurNode = upperCurNode->next;
            }
            
            //next是隔壁一个上层节点的左/右子树
            if(upperCurNode == NULL){
                break;
            } else if(upperCurNode->left){
                curNode->next = upperCurNode->left;
                curNode = curNode->next;
            } else if(upperCurNode->right){
                curNode->next = upperCurNode->right;
                upperCurNode = upperCurNode->next;
                curNode = curNode->next;
            } else{
                //隔壁也没找到，继续往下找
                upperCurNode = upperCurNode->next;
            }
        }
        curNode->next = NULL;
    }
};
