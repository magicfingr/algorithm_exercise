/*
没有指明是否带头结点，先当做不带头结点处理
错误：
没有更改merge之后的头结点
mergeList返回的头结点错误
算法有误
off-by-one * 3
算长度的时候没有累加，只后移
insertList里面改的是局部的tail
算法有误，归并后链表结构已改变
and more...
*/
/*
测试：
len = 0, 1, 2, 3, 4, 6, 10
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
	/*
	自底向上的升序归并排序
	输入：指向链表第一个节点的指针
	*/
	ListNode *sortList(ListNode *head);
private:
	/*
	归并两个链表
	*/
	void mergeList(ListNode* a, int na, ListNode* b, int nb, ListNode* &iHead, ListNode* &iTail);
	/*
	尾插法插入链表
	*/
	void insertList(ListNode* &tail, ListNode* newNode);
};

ListNode* Solution::sortList(ListNode *head){
	//计算链表长度
	int len = 0;
	ListNode* p = head;
	while (p != NULL){
		p = p->next;
		len++;
	}
	//为链表加上一个空的头结点，处理时更方便
	ListNode* newHead = new ListNode(len);
	newHead->next = head;

	//循环归并长度从 1~len/2 的链表，使链表逐渐局部有序进而全局有序
	int iLen = 1;
	while (iLen <= len){
		iLen *= 2;
		ListNode *curPos = newHead->next;
		ListNode *lastNode = newHead;
		for (int iPos = 0; iPos < len; iPos += iLen){
			//通过访问指针找到待归并的两个链表的头结点指针，以及链表长度
			ListNode* a = curPos;
			int na = ((iPos + iLen / 2) < len) ? (iLen / 2) : (len - iPos);
			for (int j = na; j > 0; j--){
				curPos = curPos->next;
			}
			ListNode* b = curPos;
			int nb = ((iPos + iLen) < len) ? (iLen / 2) : (len - iPos - na);
			for (int j = nb; j > 0; j--){
				curPos = curPos->next;
			}
			//归并两个链表，返回新链表的头、尾节点地址
			ListNode* iHead, *iTail;
			mergeList(a, na, b, nb, iHead, iTail);
			//插入到原链表
			lastNode->next = iHead;
			iTail->next = curPos;
			lastNode = iTail;
		}
	}
	return newHead->next;
}

void Solution::mergeList(ListNode* a, int na, ListNode* b, int nb, ListNode* &iHead, ListNode* &iTail){
	//先新建一个带头结点的空链表，处理时更方便
	ListNode* newList = new ListNode(-1);
	newList->next = NULL;
	//循环访问待归并的两个链表，并按元素大小用尾插法插入到新链表中
	ListNode* tail = newList;
	int apos = 0;
	int bpos = 0;
	while (apos < na && bpos < nb){
		if (a->val < b->val){
			ListNode* newNode = a;
			a = a->next;
			apos++;
			insertList(tail, newNode);
		}
		else{
			ListNode* newNode = b;
			b = b->next;
			bpos++;
			insertList(tail, newNode);
		}
	}
	//插入未访问完的链表元素
	while (apos < na){
		ListNode* newNode = a;
		a = a->next;
		apos++;
		insertList(tail, newNode);
	}
	while (bpos < nb){
		ListNode* newNode = b;
		b = b->next;
		bpos++;
		insertList(tail, newNode);
	}
	//返回头、尾节点指针
	iHead = newList->next;
	iTail = tail;
}

void Solution::insertList(ListNode* &tail, ListNode* newNode){
	newNode->next = tail->next;
	tail->next = newNode;
	tail = newNode;
}