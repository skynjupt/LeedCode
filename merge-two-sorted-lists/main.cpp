#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {};
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	if(l1 == NULL || l2 == NULL) {
		return l1 == NULL ? l2:l1;
	}
	ListNode *head = l1;
	if(l1->val > l2->val) {
		head = l2;
		l2 = l1;
		l1 = head;
	}

	/*p: the pre point of l1*/
	ListNode *p = NULL;
	ListNode *t = NULL;
	p = l1;
	l1 = l1->next;
	while(l1 != NULL && l2 != NULL) {
		if(l1->val > l2->val) {
			p->next = l2;
			t = l2->next;	
			l2->next = l1;
			p = l2;
			l2 = t;
		} else {
			p = l1;
			l1 = l1->next;
		}
	}

	if(l2 != NULL) {
		p->next = l2;	
	}

	return head;
}

ListNode *createList(int a[], int n) {
	vector<ListNode*> v;
	ListNode *p = NULL;
	for(int i = 0; i < n; i++) {
		p = new ListNode(a[i]);
		v.push_back(p);
	}

	for(int i = 0; i < n-1; i++) {
		v[i]->next = v[i+1];
	}

	return v[0];
}

void printList(ListNode *l) {
	while(l != NULL) {
		cout << l->val << ", ";
		l = l->next;
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	int a[] = {1, 3, 5, 6, 7};
	int b[] = {2, 3, 4, 8};
	ListNode *t1 = createList(a, sizeof(a)/sizeof(a[0]));
	ListNode *t2 = createList(b, sizeof(b)/sizeof(b[0]));
	printList(t1);
	printList(t2);
	ListNode *t3 = mergeTwoLists(t1, t2);
	printList(t3);
		
	return 0;
}
