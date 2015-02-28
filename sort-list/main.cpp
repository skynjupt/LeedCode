#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeList(ListNode *a, ListNode *b) {
	ListNode h(0);
	ListNode *c = &h;
	c->next = NULL;
	while(a != NULL && b != NULL) {
		if(a->val > b->val) {
			c->next = b;
			b = b->next;
		} else {
			c->next = a;
			a = a->next;
		}
		c = c->next;
		c->next = NULL;
	}	

	if( a != NULL) {
		c->next = a;
	} else if( b != NULL) {
		c->next = b;
	}

	return h.next;
}

ListNode *sortList(ListNode *head) {

	if(head == NULL || head->next == NULL) {
		return head;
	}

	ListNode *a = head;
	ListNode *b = head->next;
	while(b != NULL && b->next !=NULL) {
		head = head->next;
		b = b->next->next;
	}
	b = head->next;	
	head->next = NULL;

	head = mergeList(sortList(a), sortList(b));
	return head;
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
	t = sortList(t);
	printList(t);
	return 0;
}
