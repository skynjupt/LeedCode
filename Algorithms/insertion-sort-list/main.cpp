/*
	https://leetcode.com/problems/insertion-sort-list/
	{
		Sort a linked list using insertion sort.
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

ListNode *insertionSortList(ListNode *head) {
	if(head == NULL || head->next == NULL) {
		return head;
	}

	ListNode t(0);
	ListNode *a = &t;
	a->next = head;
	head = head->next;
	a->next->next = NULL;
	while(head != NULL) {
		a = t.next;
		ListNode *b = NULL;
		while(a != NULL && a->val < head->val) {
			b = a;
			a = a->next;
		}

		if(b == NULL) {
			a = head->next;
			head->next = t.next;
			t.next = head;
			head = a;
		} else {
			b->next = head;
			b = head->next;
			head->next = a;
			head = b;
		}
	}

	return t.next;
}

ListNode *createList(int a[], int n) {
	vector<ListNode *> v;
	for(int i = 0; i < n; i++) {
		v.push_back(new ListNode(a[i]));
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
	int a1[] = {1,3,4,8,3,2,1,5,7};
	ListNode *t = createList(a1, sizeof(a1)/sizeof(a1[0]));
	printList(t);
	t = insertionSortList(t);
	printList(t);
	return 0;
}
