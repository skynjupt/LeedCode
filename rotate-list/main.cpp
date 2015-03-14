/*
https://leetcode.com/problems/rotate-list/
{
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
/*Wrong Answer,because i don't understand rotate the list to the right by k playces */
/*
	Input: 	{1,2}, 0
	Output: 	{2,1}
	Expected: 	{1,2}	
 */ 
ListNode *rotateRight(ListNode *head, int k) {
	ListNode one(0);
	ListNode two(0);
	ListNode *pOne = &one;
	ListNode *pTwo = &two; 

	int cnt = 0;
	ListNode *p = head;
	pOne->next = head;

	while(p != NULL) {
		if(cnt == k) {
			pOne = p;
			pTwo->next = p->next;		
			pTwo = pTwo->next;
		}
		cnt++;
		if(p->next == NULL) {
			pTwo = p;
		}
		p = p->next;	
	}

	if(cnt <= k+1) {
		return head;		
	}

	pTwo->next = one.next;
	pOne->next = NULL;	

	return two.next;
}
#endif


ListNode *rotateRight(ListNode *head, int k) {
	if(head == NULL) {
		return NULL;
	}

	int cnt = 0;
	ListNode *p = head;
	while(p != NULL) {
		cnt++;
		p = p->next;
	}

	ListNode *fast = head;
	ListNode *slow = head;	
	k %= cnt;
	for(ListNode *p = head; p->next != NULL; p = p->next) {
		if(k != 0) {
			fast = fast->next;
			k--;
			continue;
		}	
		slow = slow->next;
		fast = fast->next;
	}

	fast->next = head;
	head = slow->next;	
	slow->next = NULL;

	return head;
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
	int a[] = {1, 2, 3, 4, 5};
	ListNode *head = createList(a, sizeof(a)/sizeof(int));
	printList(head);
	head = rotateRight(head, 2);
	printList(head);	

	int b[] = {1, 2};
	head = createList(b, sizeof(b)/sizeof(int));
	printList(head);
	head = rotateRight(head, 2);
	printList(head);	
	return 0;
}
