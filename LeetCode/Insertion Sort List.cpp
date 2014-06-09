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
    /*
    链表的升序插入排序
    */
    ListNode *insertionSortList(ListNode *head) {
        //新建头结点，操作更方便
        ListNode *newHead = new ListNode(-1);
        
        //循环：从第1个元素开始，依次插入到有序链表中
        ListNode *curPos = head;
        while(curPos != NULL){
            //保存当前访问的节点
            ListNode* node = curPos;
            //后移访问指针
            curPos = curPos->next;
            //循环：在有序链表中寻找插入位置（前一个节点）
            ListNode* find = newHead;
            for(; find->next != NULL; find = find->next){
                //从新链表头开始，找next比node值大的节点
                if((find->next)->val > node->val)
                    break;
            }
            //将此节点插入到有序链表
            ListNode* oldNext = find->next;
            find->next = node;
            node->next = oldNext;
        }
        return newHead->next;
    }
};
