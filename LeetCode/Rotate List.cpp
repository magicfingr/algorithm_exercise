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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL)
            return NULL;
        ListNode *preK = head;
        ListNode *p = head;
        int len = 0;
        while(p){
            len++;
            p = p->next;
        }
        k %= len;
        
        p = head;
        while(k--)
            p = p->next;
        while(p->next){
            p = p->next;
            preK = preK->next;
        }
        p->next = head;
        head = preK->next;
        preK->next = NULL;
        return head;
    }
};