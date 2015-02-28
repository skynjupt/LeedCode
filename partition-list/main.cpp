#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode *head, int x) {
	if(head == NULL) {
		return NULL;
	}

	ListNode lessHead(0);
	ListNode greaterHead(0);

	ListNode *pl = &lessHead;
	ListNode *pg = &greaterHead;
	ListNode *p = head;

	while(p != NULL) {
		if(p->val < x) {
			pl->next = p;
			pl = pl->next;
		} else {
			pg->next = p;
			pg = pg->next;
		}
		p = p->next;
	}

	pg->next = NULL;
	pl->next = greaterHead.next;

	return lessHead.next;
}

ListNode *createList(int a[], int n) {
	vector<ListNode*> v;
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
	int a[] = {1, 4, 3, 2, 5, 2};
	ListNode *head = createList(a, sizeof(a)/sizeof(int));
	printList(head);
	head = partition(head, 3);
	printList(head);	
	return 0;
}
