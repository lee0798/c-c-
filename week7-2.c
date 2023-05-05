#include<stdio.h>
#include<stdlib.h>



typedef char BData;
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
int CalDirectorySize(BTreeNode *root) {
    int left_size, right_size;
    if (root == NULL) return 0;
    else {
        left_size=CalDirectorySize(root->left_child);
        right_size=CalDirectorySize(root->right_child);
        return (root->item+left_size+right_size);
    } 
}
int CalculateExpTree(BTreeNode * root) 
{
    int op1, op2;
    if (root == NULL) return 0;
    if (root->left_child == NULL && root->right_child == NULL)
    return (root->item)-'0';
    op1 = CalculateExpTree(root->left_child);
    op2 = CalculateExpTree(root->right_child); 
    switch (root->item)
    {
        case '+':return op1+op2;
        case '-':return op1-op2;
        case '*':return op1*op2;
        case '/':return op1/op2;
    }
    return 0; 
}






int main() {

	BTreeNode* node1 = CreateNode('+');
	BTreeNode* node2 = CreateNode('+');
	BTreeNode* node3 = CreateNode('1');
	BTreeNode* node4 = CreateNode('1');
	BTreeNode* node5 = CreateNode('7');
	BTreeNode* node6 = CreateNode(6);//중위노드 구할시 주석

	
	CreateLeftSubtree(node1, node2);
	CreateRightSubtree(node1, node3);
	CreateLeftSubtree(node2, node4);
	CreateRightSubtree(node2, node5);
	CreateLeftSubtree(node3, node6);//중위노드 구할시 주석
    printf("%d",CalDirectorySize(node2));//노드 의 메모리 구하기
    printf("%d",CalculateExpTree(node1));//중위순회 노드 계산

	DestroyNode(node1);
	DestroyNode(node2);
	DestroyNode(node3);
	DestroyNode(node4);
	DestroyNode(node5);
	DestroyNode(node6);//중위노드 구할시 주석

	return 0;
}