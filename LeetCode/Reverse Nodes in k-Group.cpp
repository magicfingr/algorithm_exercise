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
     * 类似 Swap Nodes in Pairs
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        int len = 0;
        ListNode *p = newHead->next;
        while(p){
            p = p->next;
            len++;
        }
        
        int swapTimes = len / k;
        p = newHead;
        while(swapTimes--){
            ListNode *curHead = p->next;
            ListNode *curTail = curHead;
            for(int j = 1; j < k; j++){
                curTail = curTail->next;
            }
            p->next = swap(curHead, curTail->next);
            p = curHead;
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