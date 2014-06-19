/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
     * 不需真正的BST调整算法，只需每次取中点作为根节点，则最后的树一定balanced，O(N^2)
     */
    TreeNode *sortedListToBST(ListNode *head) {
        if(!head)
            return NULL;
        ListNode *left = NULL;
        ListNode *right = NULL;
        ListNode *mid = NULL;
        slice(head, left, right, mid);
        
        TreeNode *root = NULL;
        if(mid){
            root = new TreeNode(mid->val);
            root->left = sortedListToBST(left);
            root->right = sortedListToBST(right);
        }
        return root;
    }
private:
    //把链表拆成左链表、右链表以及的原链表中点
    void slice(ListNode *head, ListNode* &left, ListNode* &right, ListNode* &mid){
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *midPre = NULL;
        //最终slow会停在中点（奇数节点）或右边的中点（偶数节点）处
        while(fast && fast->next){
            fast = fast->next->next;
            midPre = slow;
            slow = slow->next;
        }
        if(midPre)
            midPre->next = NULL;    //cut
        mid = slow;
        if(mid == head){
            left = right = NULL;
        } else{
            left = head;
            right = mid->next;
        }
    }
};