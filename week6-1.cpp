//represent Binary tree using LinkedList
#include<stdio.h>
#include<stdlib.h>
typedef int BData;
typedef struct _bTreeNode
{
	BData item;
	struct _bTreeNode* left_child;
	struct _bTreeNode* right_child;
} BTreeNode;
// Create a new node.
BTreeNode* CreateNode(BData item);
// Destroy a node.
void DestroyNode(BTreeNode* node);
// Conect the root to a left-side node.
void CreateLeftSubtree(BTreeNode* root, BTreeNode* left);
// Conect the root to a right-side node.
void CreateRightSubtree(BTreeNode* root, BTreeNode* right);
// Traverse a tree.
void Inorder(BTreeNode* root);
void Preorder(BTreeNode* root);
void Postorder(BTreeNode* root);
void Levelorder(BTreeNode* root);
int main()
{
	BTreeNode* n1 = (BTreeNode*)malloc(sizeof(BTreeNode));
	BTreeNode* n2 = (BTreeNode*)malloc(sizeof(BTreeNode));
	BTreeNode* n3 = (BTreeNode*)malloc(sizeof(BTreeNode));
	n1->item = 10; // Setting the first node
	n1->left_child = n2;
	n1->right_child = NULL;
	n2->item = 20; // Setting the second node
	n2->left_child = n3;
	n2->right_child = NULL;
	n3->item = 30; // Setting the third node
	n3->left_child = NULL;
	n3->right_child = NULL;
	free(n1), free(n2), free(n3);
	return 0;
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