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
     * 反向存储，即从个位开始
     */
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        //扫一遍，带carry，然后加上剩余的
        ListNode *newHead = new ListNode(0);
        ListNode *newTail = newHead;
        int carry = 0;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        while(p1 && p2){
            int val = p1->val + p2->val + carry;
            updateValueAndCarry(val, carry);
            insertTail(newTail, val);
            p1 = p1->next;
            p2 = p2->next;
        }
        while(p1){
            int val = p1->val + carry;
            updateValueAndCarry(val, carry);
            insertTail(newTail, val);
            p1 = p1->next;
        }
        while(p2){
            int val = p2->val + carry;
            updateValueAndCarry(val, carry);
            insertTail(newTail, val);
            p2 = p2->next;
        }
        if(carry > 0)
            insertTail(newTail, carry);
        return newHead->next;
    }
private:
    void insertTail(ListNode* &tail, int val){
        assert(tail->next == NULL);
        ListNode *node = new ListNode(val);
        tail->next = node;
        tail = node;
    }
    
    void updateValueAndCarry(int &val, int &carry){
        carry = val / 10;
        val %= 10;
    }
};