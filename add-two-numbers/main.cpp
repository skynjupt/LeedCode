/*
	https://leetcode.com/problems/add-two-numbers/
	{
		You are given two linked lists representing two non-negative numbers. 
		The digits are stored in reverse order and each of their nodes contain a single digit. 
		Add the two numbers and return it as a linked list.

		Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
		Output: 7 -> 0 -> 8
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
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	if(l1 == NULL || l2 == NULL) {
		return (l1 == NULL ? l2 : l1);
	}

	ListNode head(0);
	ListNode *p = &head;	 
	int m = 0;
	int t = 0;
	while(l1 != NULL && l2 != NULL) {
		t = l1->val + l2->val + m;
		m = t / 10;
		t = t % 10;	

		p->next = new ListNode(t);
		p = p->next;		

		l1 = l1->next;
		l2 = l2->next;
	}

	ListNode *q = NULL;	
	if(l1 != NULL) {
		q = l1;	
	} else if(l2 != NULL) {
		q = l2;	
	}

	while(q != NULL) {
		cout << "q->val=" << q->val << endl;
		t = q->val + m;
		m = t / 10;
		t = t % 10;	

		p->next = new ListNode(t);
		p = p->next;		
		q = q->next;
	}

	if( m != 0) {
		p->next = new ListNode(m);
		p = p->next;		
	}
	
	return head.next;
}
#endif

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	ListNode head(0);
	ListNode *p = &head;	 
	int carry = 0;
	int sum = 0;

	while(l1 != NULL || l2 != NULL || carry != 0) {
		sum = carry;

		if(l1 != NULL) {
			sum += l1->val;
			l1 = l1->next;
		}

		if(l2 != NULL) {
			sum += l2->val;
			l2 = l2->next;
		}

		p->next = new ListNode(sum % 10);
		p = p->next;	

		carry = sum / 10;
	}
	
	return head.next;
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
	int a[] = {9, 1, 6};
	int b[] = {0};
	ListNode *l1  = createList(a, sizeof(a)/sizeof(int));
	ListNode *l2  = createList(b, sizeof(b)/sizeof(int));

	ListNode *head = addTwoNumbers(l1, l2);
	printList(head);
	
	return 0;
}
