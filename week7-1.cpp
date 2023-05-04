#include<stdio.h>
#include<stdlib.h>
#define max(X,Y) ((X) > (Y) ? (X) : (Y))


typedef int BData;
typedef struct _bTreeNode
{
	BData item;
	struct _bTreeNode* left_child;
	struct _bTreeNode* right_child;
} BTreeNode;
// Conect the root to a left-side node.
void CreateLeftSubtree(BTreeNode* root, BTreeNode* left)
{
	if (root->left_child != NULL)
		exit(1);
	root->left_child = left;
}
// Conect the root to a right-side node.
void CreateRightSubtree(BTreeNode* root, BTreeNode* right)
{
	if (root->right_child != NULL)
		exit(1);
	root->right_child = right;
}
// Create a new node.
BTreeNode* CreateNode(BData item)
{
	BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
	node->item = item;
	node->left_child = NULL;
	node->right_child = NULL;
	return node;
}
// Destroy a node.
void DestroyNode(BTreeNode* node)
{
	free(node);
}
int Nodes(BTreeNode* node)
{
	int r = 0, l = 0;
	if (node->right_child != NULL)
		r = Nodes(node->right_child);
	if (node->left_child != NULL)
		l = Nodes(node->left_child);
	return 1 + r + l;
}
int Height(BTreeNode* node)
{
	int r = 0, l = 0;
	if (node->right_child != NULL)
		r = Height(node->right_child);
	if (node->left_child != NULL)
		l = Height(node->left_child);
	return 1 + max(r, l);
}
void Inorder(BTreeNode* root)
{
	if (root != NULL)
	{
		Inorder(root->left_child);
		printf("%d ", root->item);
		Inorder(root->right_child);
	}
}
void Preorder(BTreeNode* root)
{
	if (root != NULL)
	{
		printf("%d ", root->item);
		Preorder(root->left_child);
		Preorder(root->right_child);
	}
}
void Postorder(BTreeNode* root)
{
	if (root != NULL)
	{
		Postorder(root->left_child);
		Postorder(root->right_child);
		printf("%d ", root->item);
	}
}





int main() {

	BTreeNode* node1 = CreateNode(1);
	BTreeNode* node2 = CreateNode(2);
	BTreeNode* node3 = CreateNode(3);
	BTreeNode* node4 = CreateNode(4);
	BTreeNode* node5 = CreateNode(5);
	BTreeNode* node6 = CreateNode(6);

	
	CreateLeftSubtree(node1, node2);
	CreateRightSubtree(node1, node3);
	CreateLeftSubtree(node2, node4);
	CreateRightSubtree(node2, node5);
	CreateLeftSubtree(node3, node6);
	printf("%d\n",Nodes(node1));//해당 노드의 갯수 구하는 함수
	printf("%d\n", Height(node1));//해당 노드의 height를 구하는 함수
	Inorder(node1);//LCR 방법으로 node 읽어오기
	printf("\n");
	Preorder(node1);//CLR 방법으로 node읽어오기
	printf("\n");
	Postorder(node1);//LRC방법으로 node읽어오기
	
	DestroyNode(node1);
	DestroyNode(node2);
	DestroyNode(node3);
	DestroyNode(node4);
	DestroyNode(node5);
	DestroyNode(node6);

	return 0;
}