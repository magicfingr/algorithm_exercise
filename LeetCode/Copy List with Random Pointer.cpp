/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    //把新复制的节点加到原节点后面，然后更新random，O(n), O(1)
    RandomListNode *copyRandomList(RandomListNode *head) {
        //复制节点，并将新节点插到原链表节点后
        RandomListNode *p = head;
        while(p != NULL){
            RandomListNode *copyNode = new RandomListNode(p->label);
            RandomListNode *position = p;
            p = p->next;
            insertNode(position, copyNode);
        }
        //更新新节点的random域
        RandomListNode *oldNode = head;
        while(oldNode != NULL){
            RandomListNode *newNode = oldNode->next;
            if(oldNode->random != NULL){
                newNode->random = oldNode->random->next;
            }
            oldNode = oldNode->next->next;
        }
        //取出新节点，成为新链表，注意维护原链表
        //新建两个带空头节点的链表，操作更方便
        RandomListNode *oldList = new RandomListNode(-1);
        RandomListNode *oldTail = oldList;  //尾指针
        RandomListNode *newList = new RandomListNode(-1);
        RandomListNode *newTail = newList;
        //p is a visit pointer
        p = head;
        while(p != NULL){
            RandomListNode *oldNode = p;
            RandomListNode *newNode = p->next;
            p = p->next->next;
            oldTail = insertNode(oldTail, oldNode);
            newTail = insertNode(newTail, newNode);
        }
        return newList->next;
    }
    
    //将newNode插入到pos之后，并返回newNode在链表中的位置
    RandomListNode* insertNode(RandomListNode *pos, RandomListNode* newNode){
        newNode->next = pos->next;
        pos->next = newNode;
        return newNode;
    }
};
