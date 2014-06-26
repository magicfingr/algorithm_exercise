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
     * 快排的子函数
     */
    ListNode *partition(ListNode *head, int x) {
        //存成两个链表，然后合并
        ListNode *lessHead = new ListNode(-1);
        ListNode *lessTail = lessHead;
        ListNode *greaterHead = new ListNode(-1);
        ListNode *greaterTail = greaterHead;
        
        ListNode *cur = head;
        while(cur != NULL){
            if(cur->val < x){
                insertTail(lessTail, cur);
            } else{
                insertTail(greaterTail, cur);
            }
            cur = cur->next;
        }
        //合并
        lessTail->next = greaterHead->next;
        greaterTail->next = NULL;
        
        return lessHead->next;
    }
private:
    void insertTail(ListNode* &tail, ListNode *newNode){
        tail->next = newNode;
        tail = newNode;
    }
};