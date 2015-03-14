/*
	https://leetcode.com/problems/remove-nth-node-from-end-of-list/
	{
	Given a linked list, remove the nth node from the end of list 
	and return its head.

	For example,

	   Given linked list: 1->2->3->4->5, and n = 2.

	   After removing the second node from the end, 
	   the linked list becomes 1->2->3->5.
	Note:
	Given n will always be valid.
	Try to do this in one pass.
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
ListNode *removeNthFromStart(ListNode *head, int n) {
	if(head == NULL) {
		return NULL;
	}
	if(n == 1) {
		return head->next;
	}
	ListNode *p, *q;

	q = head;
	while(--n) {
		p = q;
		q = q->next;				
	}

	if(q != NULL) {
		p->next = q->next;
	} else {
		p->next = NULL;
	}

	return head;
}

ListNode *removeNthFromEnd(ListNode *head, int n) {
	int cnt = 0;
	ListNode *p = head;
	while(p!=NULL) {
		cnt++;
		p = p->next;
	}

	return removeNthFromStart(head, cnt-n+1);
}
#endif

ListNode *removeNthFromEnd(ListNode *head, int n) {
	if(head == NULL) {
		return NULL;
	}	

	ListNode *fast = head; 
	ListNode *slow = head;
	while(n--) {
		fast = fast->next;
	}

	if(fast == NULL) {
		return slow->next;
	}

	while(fast->next != NULL) {
		fast = fast->next;
		slow = slow->next;
	}

	slow->next = slow->next->next;
	return head;
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
	int a[] = {1};
	ListNode *p = createList(a, sizeof(a)/sizeof(a[0]));
	p = removeNthFromEnd(p, 1);
	printList(p);
				
	int b[] = {1,2,3,4};
	p = createList(b, sizeof(b)/sizeof(b[0]));
	p = removeNthFromEnd(p, 1);
	printList(p);

	int c[] = {1,2,3,4};
	p = createList(c, sizeof(c)/sizeof(c[0]));
	p = removeNthFromEnd(p, 3);
	printList(p);

	int d[] = {1,2,3,4};
	p = createList(d, sizeof(d)/sizeof(d[0]));
	p = removeNthFromEnd(p, 4);
	printList(p);
	return 0;
}
