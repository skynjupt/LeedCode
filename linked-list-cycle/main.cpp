#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {};
};

bool hasCycle(ListNode *head) {
	ListNode *slower = head;
	ListNode *faster = head;
	while(faster != NULL && faster->next != NULL) {
		slower = slower->next;
		faster = faster->next->next;
		if(faster == slower) {
			return true;
		}
	}

	return false;	
}

ListNode *detectCycle(ListNode *head) {
	ListNode *slower = head;
	ListNode *faster = head;
	while(faster != NULL && faster->next != NULL) {
		slower = slower->next;
		faster = faster->next->next;
		if(faster == slower) {
			faster = head;
			while(faster != slower) {
				faster = faster->next;
				slower = slower->next;			
			}	
			return faster;
		}
	}
	return NULL;	
}

int main(int argc, char *argv[]) {
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);	
	a.next = &b;
	b.next = &c;
	c.next = NULL;	
	cout << hasCycle(&a) << endl;
	c.next = &a;
	cout << hasCycle(&a) << endl;
	return 0;
}
