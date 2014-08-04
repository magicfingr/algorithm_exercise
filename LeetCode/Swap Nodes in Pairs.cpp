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
    /**
     * 遍历，原地交换（头插）
     */
    ListNode *swapPairs(ListNode *head) {
        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        ListNode *p = newHead;
        while(p->next && p->next->next){
            ListNode *curHead = p->next;
            ListNode *curTail = curHead->next;
            p->next = swap(curHead, curTail->next);
            p = curHead;    //after swap, curHead becomes tail
        }
        return newHead->next;
    }
private:
    ListNode *swap(ListNode *head, ListNode *originNext){
        ListNode *newHead = new ListNode(-1);
        newHead->next = originNext;
        ListNode *p = head;
        while(p != originNext){
            ListNode *node = p;
            p = p->next;
            insertHead(newHead, node);
        }
        return newHead->next;
    }
    
    void insertHead(ListNode *head, ListNode *node){
        node->next = head->next;
        head->next = node;
    }
};