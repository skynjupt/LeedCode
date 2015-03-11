/*
 * HarryWu
 * 2014-11-01 9:23 am
 * P:
 * 	Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 *	For example:
 *	Given binary tree {3,9,20,#,#,15,7},
 *	   	  3
 *  		/ \
 * 		9  20
 *   		/  \
 *  		15   7
 *  	return its level order traversal as:
 *  	[
 * 		[3],
 * 		[9,20],
 * 		[15,7]
 *	]
 *
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

#define MAX_NUM 100

TreeNode *A[MAX_NUM];
TreeNode *B[MAX_NUM];

TreeNode *root = NULL;
int num = -1;

void insertNode(TreeNode *t)
{
	if(root == NULL)
	{
		root = t;
		return;
	}	
	
	if(num % 2 == 0)
	{
		A[(num-1) / 2]->right = t;	
	}		
	else
	{
		A[(num-1) / 2]->left = t;
	}
}

TreeNode makeNode(int val)
{
	TreeNode node;
	node.val = val;
	node.left = node.right = NULL;
	return node;
}

void makeTree()
{
	char c = 0;
	int t = 0, flag = 0;
	TreeNode *pnode = NULL;
	
	while(scanf("%c", &c) != EOF)
	{
		if(c == '{')
		{
//			printf("%d ", t);
			continue;
		}
#if 0
		else if(c == '}')
		{
			continue;
		}
#endif
		else if((c == ',') || (c == '}'))
		{
//			printf("%d ", t);
			
			if(flag)
			{
				// null
				flag = 0;
				++num;
				insertNode(NULL);	
			}
			else
			{
				pnode = (TreeNode*) malloc(sizeof(TreeNode));
				if(pnode == NULL)
					break;		
				*pnode = makeNode(t);
				A[++num] = pnode;
				insertNode(pnode);	
			}
			t = 0;
			continue;
		}
		else if(c == '#')
		{
			flag = 1;
			continue;
		}
		else
		{
			t = 10 * t + c - '0';		
		}
	}
}

void visit(TreeNode *p)
{
	if(p != NULL)
		printf("%d ", p->val);
}

void preOrder(TreeNode *p)
{
	if(p->left != NULL)
		preOrder(p->left);
	visit(p);	
	if(p->right != NULL)
		preOrder(p->right);
}

void levelOrder(TreeNode *root) 
{
	int n=1, i=0, total = 1, top = 0, last = 0;
	TreeNode *p;
	if(root == NULL)
		return;	
	B[top++] = root;
	printf("[\n");
	while(last != top)
	{
		p = B[last++];
		if(p == NULL) continue;
		i++;
		if(n == i)
		{
			printf("\t[");
		}
		
		printf("%d", p->val);			
		B[top++] = p->left;
		B[top++] = p->right;

		if(i == total)
		{
			printf("]\n");
			n = 2 * n;
			total = total + n;
		}
		else
		{
			printf(",");
		}
	}
	printf("]\n");
}

int main(int argc, char *argv[])
{
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	makeTree();
//	preOrder(root);
	levelOrder(root);	
	fclose(stdin);
//	fclose(stdout);

	return 0;
}
