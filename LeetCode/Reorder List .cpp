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
    void reorderList(ListNode *head) {
        //O(n), O(1)，第一个节点位置不变
        if(head == NULL)
            return;
        //找链表中点
        ListNode *mid = findMid(head);
        //将链表切成两段
        ListNode *firstHalf = head;
        ListNode *lastHalf = mid->next;
        mid->next = NULL;
        //将链表后半部反向成为reverseList
        lastHalf = reverseList(lastHalf);
        //循环，间隔插入
        ListNode *tail = firstHalf;
        firstHalf = firstHalf->next;
        while(firstHalf != NULL && lastHalf != NULL){
            tail->next = lastHalf;
            tail = tail->next;
            lastHalf = lastHalf->next;
            
            tail->next = firstHalf;
            tail = tail->next;
            firstHalf = firstHalf->next;
        }
        if(firstHalf != NULL)
            tail->next = firstHalf;
        if(lastHalf != NULL)
            tail->next = lastHalf;
    }
    
    //head非空
    ListNode* findMid(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode *head){
        //add an empty head node
        ListNode* re = new ListNode(0);
        ListNode *p = head;
        while(p != NULL){
            ListNode *node = p;
            p = p->next;
            //insert in the head
            node->next = re->next;
            re->next = node;
        }
        return re->next;
    }
};
