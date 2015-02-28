#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *swapPairs(ListNode *head) {
	if(head == NULL || head->next == NULL) {
		return head;
	}

	ListNode ans(0);
	ListNode *p = &ans;
	ListNode *q = head;

	while(q != NULL && q->next != NULL) {
		p->next = q->next;
		p = p->next;
		q->next = p->next;
		p->next = q;
		p = p->next;
		q = q->next;
	}

	return ans.next;
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
		cout << head->val << ", ";
		head = head->next;
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	int a[] = {1, 2, 3, 4, 5};
	ListNode *head = createList(a, sizeof(a)/sizeof(int));
	printList(head);
	head = swapPairs(head);
	printList(head);
	return 0;
}
