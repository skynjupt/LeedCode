#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if(headA == NULL || headB == NULL)
		return NULL;
	ListNode *p = headA;
	ListNode *q = headB;
	while(p != NULL && q != NULL && p != q) {
		p = p->next;
		q = q->next;
		if(p == q)
			return p;
		if(p == NULL) p = headB;
		if(q == NULL) q = headA;
	}
	return p;
}

ListNode *createList(int a[], int n) {
	if (n<=0) return NULL;
	ListNode *list = NULL; 
	ListNode *p = NULL;
	list = p = new ListNode(a[0]);
	for(int i = 1; i < n; i++) {
		p->next = new ListNode(a[i]);
		p = p->next;	
	}
	return list;
}

void createIntersectionList(ListNode *a, ListNode *b, ListNode *c) {
	if(a == NULL || b == NULL) return;
	while(a != NULL && a->next != NULL) a = a->next;
	while(b != NULL && b->next != NULL) b = b->next;
	a->next = c;
	b->next = c;
}

void visit(ListNode *p) {
	while( p!=NULL ) {
		cout << p->val;
		if(p->next != NULL) 
			cout << ","; 
		p = p->next;
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	int a[] = {1, 2, 3, 4};
	int b[] = {5,6};
	int c[] = {7,8};
	ListNode *p1 = createList(a, sizeof(a)/sizeof(a[0]));
	ListNode *p2 = createList(b, sizeof(b)/sizeof(b[0]));
	ListNode *p3 = createList(c, sizeof(c)/sizeof(c[0]));
//	createIntersectionList(p1, p2, NULL);
	createIntersectionList(p1, p2, p3);
	visit(p1);
	visit(p2);
	ListNode *t = getIntersectionNode(p1, p2);
	if(t != NULL) cout << t->val << endl;
	return 0;
}

