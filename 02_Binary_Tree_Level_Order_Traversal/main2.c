/*
 * HarryWu
 * 2014-11-01 9:23 am
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 100 

typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

// FIFO {{
static TreeNode **q;
static int N, head, tail;

void queueInit(int maxN)
{
	q = (TreeNode **) malloc(sizeof(TreeNode*)*(maxN+1));
	N = maxN + 1;
	head = N;
	tail = 0;
}

int queueEmpty(void)
{
	return head % N == tail;
}

void queuePut(TreeNode *item)
{
	q[tail++] = item;
	tail = tail % N;
}

TreeNode *queueGet(void)
{
	head = head % N;
	return q[head++];
}

// FIFO }}

TreeNode* createTree(int a[], int n)
{
	int i = 0, pos = 1;
	TreeNode *p = NULL;	
	TreeNode **tree = NULL;

	if(n == 0) return NULL;

	tree = (TreeNode **)malloc(sizeof(TreeNode*) * MAX_NUM);	

	for(i = 0; i < n; i++)
	{
		if(a[i] == 0)
		{
			tree[i] = NULL;
			continue;
		}
		
		p = (TreeNode*) malloc(sizeof(TreeNode));
		p->val = a[i];
		p->left = NULL;
		p->right = NULL;
		tree[i] = p;
	}		

	for(i = 0; i < n && pos < n; i++)
	{
		if(tree[i])
		{
			tree[i]->left = tree[pos++];	
			if(pos < n) tree[i]->right = tree[pos++];
		}
	}	

	return tree[0];
}

void levelTraverse(TreeNode *root, int max)
{
	TreeNode *p = NULL;

	queueInit(max);
	queuePut(root);
	while(!queueEmpty())
	{
		p = queueGet();			
		if(p != NULL)
		{
			printf(" %d",  p->val);
			if(p->left != NULL) queuePut(p->left);
			if(p->right != NULL) queuePut(p->right);
		}	
	}
	printf("\n");
}

/*vv[][0]: num of valid data*/
static int vv[MAX_NUM][MAX_NUM+1]; 

void levelOrder(TreeNode *root, int max) 
{
	int i, j, k, cnd, step = 1, level = 0;	
	TreeNode **vt = (TreeNode**) malloc(sizeof(TreeNode*) * max);
	TreeNode *p;
#if 1
	for(i = 0; i < MAX_NUM; i++)
	{
		for(j = 0; j < MAX_NUM; j++)
			vv[i][j] = 0;
	}
#endif
	i = 0;
	queueInit(max);
	queuePut(root);
	while(!queueEmpty())
	{
		p = queueGet();			
		vt[i++] = p;
		if(p != NULL)
		{
//			if(p->left != NULL) queuePut(p->left);
//			if(p->right != NULL) queuePut(p->right);
			queuePut(p->left);
			queuePut(p->right);
		}	
	}

	for(i = 0; i < max; i = j)
	{
		cnd = 0;
		k = 1;
		for(j = i; (j < i+step) && (j < max) ; j++)
		{
			
			if(vt[j])
			{
				vv[level][k++] = vt[j]->val;	
				vv[level][0]++;
				cnd += 2;
			}
		}		
		step = cnd;
		level++;
	}

	printf("[\n");
	for(i = 0; i < level; i++)
	{
		printf(" [");	
		for(j = 1; j <= vv[i][0]; j++)
		{
			if(vv[i][j] == 0)
				break;
			printf("%d", vv[i][j]);	
			if(j < vv[i][0])
				printf(",");
		}	
		printf("]");	
		if(i + 1 < level)
			printf(",");
		printf("\n");
	}
	
	printf("]\n");

}

int main(int argc, char *argv[])
{
	TreeNode *p = NULL;

	int a[] = {3, 9, 20, 0, 0, 15, 7};
	p = createTree(a, sizeof(a)/sizeof(a[0]));	
	levelTraverse(p, sizeof(a)/sizeof(a[0]));	
	levelOrder(p, sizeof(a)/sizeof(a[0]));

	int b[] = {1, 2, 3, 4, 5, 0, 0};
	p = createTree(b, sizeof(b)/sizeof(b[0]));	
	levelTraverse(p, sizeof(b)/sizeof(b[0]));	
	levelOrder(p, sizeof(b)/sizeof(b[0]));
	
	int c[] = {1, 0, 2, 3};
	p = createTree(c, sizeof(c)/sizeof(c[0]));	
	levelTraverse(p, sizeof(c)/sizeof(c[0]));	
	levelOrder(p, sizeof(c)/sizeof(c[0]));

	int d[] = {1, 2, 0, 3, 0, 4, 0, 5};
	p = createTree(d, sizeof(d)/sizeof(d[0]));	
	levelTraverse(p, sizeof(d)/sizeof(d[0]));	
	levelOrder(p, sizeof(d)/sizeof(d[0]));

	int e[] = {1, 2, 3, 4, 0, 0, 5};
	p = createTree(e, sizeof(e)/sizeof(e[0]));	
	levelTraverse(p, sizeof(e)/sizeof(e[0]));	
	levelOrder(p, sizeof(e)/sizeof(e[0]));
	return 0;
}
