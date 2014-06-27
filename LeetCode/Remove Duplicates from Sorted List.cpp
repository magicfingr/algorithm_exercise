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
    ListNode *deleteDuplicates(ListNode *head) {
        //新建链表，遍历原链表，存下上一个点的值，若不同则加入到新链表
        if(!head)
            return NULL;
        ListNode *newList = new ListNode(-1);
        //加入第一个点
        newList->next = head;
        ListNode *newListTail = head;
        int last = head->val;
        ListNode *p = head->next;
        while(p){
            if(p->val != last){
                insert(newListTail, p);
                last = p->val;
            }
            p = p->next;
        }
        //结束新链表
        newListTail->next = NULL;
        return newList->next;
    }
private:
    void insert(ListNode* &tail, ListNode *node){
        tail->next = node;
        tail = node;
    }
};