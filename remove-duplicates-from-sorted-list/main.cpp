#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

#if 0
ListNode *deleteDuplicates(ListNode *head) {
	if(head == NULL)
		return NULL;
	
	ListNode *p, *q, *t;
	p = q = head;
	while(p!=NULL) {
		q = p->next;
		while(q != NULL && p->val == q->val) {
			t = q;
			q = q->next;
			delete t;
			t = NULL;
		}
		if(p->next != q) {
			p->next = q;
		}
		p = q; 
	}
	return head;
}
#endif

ListNode *deleteDuplicates(ListNode *head) {
	if(head == NULL)
		return NULL;
	stack<ListNode*> st;	
	
	ListNode *p, *q;
	p = q = head;
	st.push(head);
	while(p!=NULL) {
		q = p->next;
		while(q != NULL && p->val == q->val) {
			q = q->next;
		}
		if(p->next != q) {
			st.pop();
		}
		p = q;
		if(p != NULL) {
			st.push(p);
		}
	}

	if(st.size() > 0) {
		q = NULL;
		while(st.size() > 0) {
			p = st.top();
			st.pop();
			p->next = q;
			q = p;
		}
		head = p;
	
	} else {
		head = NULL;
	}
	
	return head;
}

ListNode *createLinkList(int a[], int n) {
	ListNode **pl = new ListNode*[n];
	
	for(int i = 0; i < n; i++) {
		pl[i] = new ListNode(a[i]);
	} 
	
	for(int i = 0; i < n-1; i++) {
		pl[i]->next = pl[i+1];
	}
	
	return pl[0];
}

void printLinkList(ListNode *head) {
	if(head == NULL) {
		return;
	}
	
	ListNode *p = head;
	
	while(p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	int a[] = {1, 1, 2};
	ListNode *p = createLinkList(a, sizeof(a)/sizeof(a[0]));
	cout << "old linkList:" << endl;
	printLinkList(p);
	p = deleteDuplicates(p);
	cout << "new linkList:" << endl;
	printLinkList(p);
	
	int b[] = {1, 1, 2, 3, 3};
	p = createLinkList(b, sizeof(b)/sizeof(b[0]));
	cout << "old linkList:" << endl;
	printLinkList(p);
	p = deleteDuplicates(p);
	cout << "new linkList:" << endl;
	printLinkList(p);	

	int c[] = {1, 2, 2, 3, 3, 4};
	p = createLinkList(c, sizeof(c)/sizeof(c[0]));
	cout << "old linkList:" << endl;
	printLinkList(p);
	p = deleteDuplicates(p);
	cout << "new linkList:" << endl;
	printLinkList(p);	
	
	return 0;
}
