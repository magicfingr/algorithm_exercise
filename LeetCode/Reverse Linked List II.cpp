/*
{1,2,3,4},0,2
{},0,0
*/
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
	//只让扫一遍，扫的时候就要同时反转，注意反转的是 [m,n]
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		//给原链表加个头结点
		ListNode* newHead = new ListNode(-1);
		newHead->next = head;

		//找位置m的前驱节点
		ListNode *preM = newHead;
		int pos = 0;
		while (pos + 1 < m){
			preM = preM->next;
			pos++;
		}
		//到达位置m以前，将所有节点头插到新链表
		if (m == n)
			return head;
		ListNode *newListHead = new ListNode(-1);
		ListNode *cur = preM->next;
		pos++;
		ListNode *newListTail = cur;  //第一个插入的节点即为尾节点
		while (pos <= n){
			ListNode *newNode = cur;
			cur = cur->next;
			pos++;
			insertHead(newListHead, newNode);
		}
		//插入到原链表：更新m前驱与n的next域
		newListTail->next = cur;
		preM->next = newListHead->next;
		return newHead->next;
	}
private:
	//头插到链表
	void insertHead(ListNode *head, ListNode *newNode){
		newNode->next = head->next;
		head->next = newNode;
	}
};