/*
	https://leetcode.com/problems/reorder-list/
	{
	Given a singly linked list L: L0->L1->бн->Ln-1->Ln,
	reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->бн

	You must do this in-place without altering the nodes' values.

	For example,
	Given {1,2,3,4}, reorder it to {1,4,2,3}.
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

void reorderList(ListNode *head) {
	if(head == NULL) {
		return;
	}
	vector<ListNode*> v;
	ListNode *p = head;
	while(p != NULL) {
		v.push_back(p);
		p = p->next; 
	}

	int n = v.size();
	for(int i = 0; i < n/2; i++) {
		v[n-i-1]->next = v[i+1];
		v[i]->next = v[n-i-1];
	}
	v[n/2]->next = NULL;

	head = v[0];
}

ListNode* createList(int a[], int n) {
	vector<ListNode*> v;
	for(int i = 0; i < n; i++) {
		ListNode *t = new ListNode(a[i]);
		v.push_back(t);
	}

	for(int i = 0; i < n-1; i++) {
		v[i]->next = v[i+1];	
	}

	return v[0];
}

void printList(ListNode *head) {
	while(head != NULL) {
		cout << head->val << ",";
		head = head->next;
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	int a[] = {1, 2, 3, 4, 5};
	ListNode *p = createList(a, sizeof(a)/sizeof(int));
	reorderList(p);
	printList(p);

	int b[] = {1, 2, 3, 4};
	p = createList(b, sizeof(b)/sizeof(int));
	reorderList(p);
	printList(p);

	int c[] = {1};
	p = createList(c, sizeof(c)/sizeof(int));
	reorderList(p);
	printList(p);
	return 0;
}
