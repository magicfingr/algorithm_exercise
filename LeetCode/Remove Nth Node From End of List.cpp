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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        ListNode *fast = head;
        ListNode *slowPre = newHead;
        while(n--){
            assert(fast != NULL);
            fast = fast->next;
        }
        while(fast){
            fast = fast->next;
            slowPre = slowPre->next;
        }
        ListNode *p = slowPre->next;
        slowPre->next = p->next;
        head = newHead->next;
        delete p;
        delete newHead;
        return head;
    }
};