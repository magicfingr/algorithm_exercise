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
        //扫一遍，若当前值不等于现在重复的节点，且不等于后继节点的值，则可加入到新链表
        ListNode *newList = new ListNode(-1);
        ListNode *newListTail = newList;
        ListNode *p = head;
        int repeat = INT_MAX;
        while(p){
            if(p->val != repeat){
                if(p->next && p->val == p->next->val){
                    repeat = p->val;
                    p = p->next;
                } else{
                    insert(newListTail, p);
                }
            }
            p = p->next;
        }
        //结束链表
        newListTail->next = NULL;
        return newList->next;
    }
private:
    void insert(ListNode* &tail, ListNode *node){
        tail->next = node;
        tail = node;
    }
};