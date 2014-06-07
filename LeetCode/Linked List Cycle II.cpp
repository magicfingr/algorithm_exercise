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
    ListNode *detectCycle(ListNode *head) {
        //先用快慢指针判断有没有环
        ListNode *slow = head;
        ListNode *fast = head;
        bool hasLoop = false;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                hasLoop = true;
                break;
            }
        }
        //若有环，快指针从头，慢指针从当前位置开始访问，直至相遇则为环入口
        if(hasLoop){
            fast = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        } else{
            return NULL;
        }
    }
};