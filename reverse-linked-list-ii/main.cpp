/*
https://leetcode.com/problems/reverse-linked-list-ii/
{
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ¡Ü m ¡Ü n ¡Ü length of list.
}
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

#if 0
ListNode *reverseBetween(ListNode *head, int m, int n) {
	if(head == NULL || m == n) {
		return head;
	}
	ListNode One(0);
	ListNode Two(0);
	ListNode *pOne = &One;
	ListNode *pTwo = &Two;

	ListNode *q = head;
	ListNode *p = NULL;
	ListNode *t = NULL;
	int cnt = 0;

	while(q != NULL) {
		cnt++;
		t = q->next;
		if(cnt < m) {
			pOne->next = q;
			pOne = pOne->next;
		} else if (cnt == m){
			pTwo->next = q;
			pTwo = pTwo->next;	
		} else if (cnt < n){
			q->next = p;
		} else if(cnt == n){
			pOne->next = q;
			Two.next->next = q->next;
			q->next = p;
			break;
		}
		p = q;
		q = t;
	}	
	return One.next;	
}
#endif

ListNode *reverseBetween(ListNode *head, int m, int n) {
	if(m == n) return head;
	n-=m;
	ListNode prehead(0);	
	prehead.next = head;
	ListNode *pre = &prehead;
	while(--m) pre = pre->next;

	ListNode *pstart = pre->next;
	while(n--) {
		ListNode *t = pstart->next;
		pstart->next = t->next;
		t->next = pre->next;
		pre->next = t;	
	}
	return prehead.next;
}

ListNode *createList(int a[], int n) {
	vector<ListNode* > vl;
	for(int i = 0; i < n; i++) {
		ListNode *p = new ListNode(a[i]);
		vl.push_back(p);
	}

	for(int i = 0; i < n-1; i++) {
		vl[i]->next = vl[i+1];
	}	

	return vl[0];
}

void printList(ListNode *head) {
	if(head == NULL) {
		cout << "NULL" << endl;
		return;
	}
	while(head != NULL) {
		cout << head->val << ",";
		head = head->next;
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	int a[] = {1, 2, 3, 4, 5};
	ListNode *head = createList(a, sizeof(a)/sizeof(a[0]));
	printList(head);
	head = reverseBetween(head, 1, 2);
	printList(head);	
	return 0;
}
