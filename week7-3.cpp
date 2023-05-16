//levelorder
#include<stdio.h>
#include<stdlib.h>
typedef int BData;
typedef struct _bTreeNode
{
    BData item;
    struct _bTreeNode* left_child;
    struct _bTreeNode* right_child;
} BTreeNode;
//Dynamic Queue
typedef struct _Node
{
    BTreeNode* item;
    struct _Node* next;
} Node;
typedef struct
{
    Node* front;
    Node* rear;
} DQueue;
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


void InitQueue(DQueue* pqueue)
{
    pqueue->front = pqueue->rear = NULL;
}
// Check whether a queue is empty.
bool IsEmpty(DQueue* pqueue)
{
    return pqueue->front == NULL;
}
// Read the item at the front.
BTreeNode* Peek(DQueue* pqueue)
{
    if (IsEmpty(pqueue)) exit(1);
    return pqueue->front->item;
}
void EnQueue(DQueue* pqueue, BTreeNode* item)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;
    if (IsEmpty(pqueue))
        pqueue->front = pqueue->rear = newNode;
    else {
        pqueue->rear->next = newNode;
        pqueue->rear = newNode;
    }
}
void DeQueue(DQueue* pqueue)
{
    Node* temp;
    if (IsEmpty(pqueue)) exit(1);
    temp = pqueue->front;
    if (temp->next == NULL)
        pqueue->front = pqueue->rear = NULL;
    else
        pqueue->front = temp->next;
    free(temp);
}


void Levelorder(BTreeNode* root) {
    DQueue queue;
    if (root == NULL){
        return;
    }else{
        InitQueue(&queue);
        EnQueue(&queue, root);
        }
    while (!IsEmpty(&queue))
    {
        root = Peek(&queue);
        DeQueue(&queue);
        printf("%d ", root->item);
        if (root->left_child != NULL)
            EnQueue(&queue, root->left_child);
        if (root->right_child != NULL)
            EnQueue(&queue, root->right_child);
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
    
    Levelorder(node1);

    DestroyNode(node1);
    DestroyNode(node2);
    DestroyNode(node3);
    DestroyNode(node4);
    DestroyNode(node5);
    DestroyNode(node6);

    return 0;
}
 
 //make exp tree
#include<stdio.h>
#include<stdlib.h>
typedef int BData;

typedef struct _bTreeNode
{
    BData item;
    struct _bTreeNode* left_child;
    struct _bTreeNode* right_child;
} BTreeNode;
typedef struct _Node
{
    BTreeNode* item;
    struct _Node* next;
} Node;
typedef struct
{
    Node* top;
} DStack;

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



void InitStack(DStack* pstack)
{
    pstack->top = NULL;
}
// check whether stack is empty.
bool IsEmpty(DStack* pstack)
{
    return pstack->top == NULL;
}
// Read the item at the top.
BTreeNode* Peek(DStack* pstack)
{
    if (IsEmpty(pstack))
        exit(1);
    return pstack->top->item;
}
void Push(DStack * pstack, BTreeNode* item)
{
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->item= item;
        newNode->next = pstack->top;
        pstack->top = newNode;
}
// Remove the item at the top.
void Pop(DStack* pstack)
{
    Node* temp;
    if (IsEmpty(pstack)) exit(1);
    temp = pstack->top;
    pstack->top = pstack->top->next;
    free(temp);
}

BTreeNode* MakeExpTree(char* exp, int len)
{
    DStack stack;
    BTreeNode * node, *right_node, *left_node;
    InitStack(&stack);
    for (int i = 0; i < len; i++)
    {
        if ('0' <= exp[i] && exp[i] <= '9')
            node = CreateNode(exp[i]);
        else{
            right_node = Peek(&stack);
            Pop(&stack);
            left_node = Peek(&stack);
            Pop(&stack);
            node = CreateNode(exp[i]);
            CreateRightSubtree(node, right_node);
            CreateLeftSubtree(node, left_node);
            }
            Push(&stack, node);
        }
        return Peek(&stack);
}
void inorder(BTreeNode* root){
    if(root != NULL){
        inorder(root->left_child);
        printf("%c ", root->item);
        inorder(root->right_child);
    }
}

int main(){
    char exp[5] = {'3','5','2','*','+'};
    BTreeNode* a;
    a = MakeExpTree(exp, 5);
    inorder(a);
    
}
