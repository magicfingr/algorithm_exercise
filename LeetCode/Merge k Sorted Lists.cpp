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
     * 2路归并
     * O(NlogK), O(K)
     */ 
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        queue<ListNode*> listQueue;
        if(lists.size() == 0)
            return NULL;
        if(lists.size() == 1)
            return lists[0];
        for(size_t i = 0; i < lists.size(); i++){
            if(i + 1 < lists.size()){
                listQueue.push(mergeList(lists[i], lists[i + 1]));
                i++;
            } else
                listQueue.push(lists[i]);
        }
        while(listQueue.size() >= 2){
            ListNode *l1 = listQueue.front();
            listQueue.pop();
            ListNode *l2 = listQueue.front();
            listQueue.pop();
            listQueue.push(mergeList(l1, l2));
        }
        return listQueue.front();
    }
private:
    ListNode *mergeList(ListNode *l1, ListNode *l2){
        ListNode *newHead = new ListNode(-1);
        ListNode *tail = newHead;
        while(l1 && l2){
            ListNode *node;
            if(l1->val <= l2->val){
                node = l1;
                l1 = l1->next;
            } else{
                node = l2;
                l2 = l2->next;
            }
            insertTail(tail, node);
        }
        if(l1){
            tail->next = l1;
        } else{
            tail->next = l2;
        }
        return newHead->next;
    }
    
    void insertTail(ListNode* &tail, ListNode *node){
        tail->next = node;
        tail = node;
    }
};