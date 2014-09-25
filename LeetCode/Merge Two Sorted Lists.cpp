/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *newHead = new ListNode(-1);
        ListNode *newTail = newHead;
        while(l1 && l2){
            if(l1->val < l2->val){
                insertTail(newTail, l1);
                l1 = l1->next;
            } else{
                insertTail(newTail, l2);
                l2 = l2->next;
            }
        }
        if(l1)
            newTail->next = l1;
        if(l2)
            newTail->next = l2;
        return newHead->next;
    }
private:
    void insertTail(ListNode* &tail, ListNode *node){
        tail->next = node;
        tail = node;
    }
};