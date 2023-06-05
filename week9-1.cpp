//
//  week9-1.cpp
//  cworkspace
//
//  Created by 이도환 on 2023/06/05.
//

#include <stdio.h>
#include <stdlib.h>

typedef int Key;
typedef struct _BSTNode
{
    Key key;
    struct _BSTNode * left_child;
    struct _BSTNode * right_child;
} BSTNode;
// Create a new node.
BSTNode* CreateNode(Key key);
void CreateLeftSubtree(BSTNode* root, Key key);
void CreateRightSubtree(BSTNode* root, Key key);
// Destroy a node.
void DestroyNode(BSTNode* node);
// Verify whether the tree is a binary search tree or not.
bool Verify(BSTNode* root);
// Search an item in BST.
BSTNode* Search(BSTNode* root, Key key); // Insert an item to BST.
void Insert(BSTNode* root, Key key);
// Remove an item from BST.
BSTNode* Remove(BSTNode* node, Key key);
// Traverse BST (the inorder traversal)
void Traverse(BSTNode* root); // Clear a tree.
void ClearTree(BSTNode* root);
// Initialize the minimum and maximum as INT_MIN and INT_MAX
void inorder(BSTNode* root);

int main(){
        BSTNode* root = CreateNode(20);
        Insert(root, 10);
        Insert(root, 30);
        Insert(root, 40);
        Remove(root,30);
        Insert(root, 5);
        BSTNode* cur = Search(root,10);
        printf("%d\n",cur->key);
        if(Verify(root)){
            inorder(root);
        }
        else{
            printf("err");
        }
    return 0;
}





bool Verify(BSTNode* root){
    if (root == NULL) {
        return true;
    }
    if (root->left_child != NULL && root->key <= root->left_child->key) {
        return false;
    }
    if (root->right_child != NULL && root->key >= root->right_child->key) {
        return false;
    }
    return Verify(root->left_child) && Verify(root->right_child);
}
BSTNode* Search(BSTNode* root, Key key) {
    if (root == NULL || root->key == key) return root; else if (root->key > key)
        return Search(root->left_child, key);
    else
        return Search(root->right_child, key);
}
/*BSTNode* Search(BSTNode* root, Key key) {//version of lterative
    BSTNode* cur = root;
    while (cur != NULL) {
        if (cur->key == key) break;
        else if (cur->key > key)
            cur = cur->left_child;
        else
            cur = cur->right_child;
    }
    return cur;
    
}*/
void Insert(BSTNode* root, Key key)
{
    if (root->key == key) exit(1);
    else if (root->key > key) {
        // Insert a new node for a left child.
        if (root->left_child == NULL) CreateLeftSubtree(root, key);
        else
            Insert(root->left_child, key);
    }
    else{
        // Insert a new node for a right child.
        if (root->right_child == NULL)
            CreateRightSubtree(root, key);
        else
            Insert(root->right_child, key);
    }

}
/*void Insert(BSTNode* root, Key key) {
    BSTNode* cur = root;
    while (cur != NULL) {
        if (cur->key == key) exit(1);
        else if (cur->key > key) {
            // Insert a new node for a left child.
            if (cur->left_child == NULL) {
                CreateLeftSubtree(cur, key);
                break;
            } else
                cur = cur->left_child;
        }
        else {
            // Insert a new node for a right child.
            if (cur->right_child == NULL) {
                CreateRightSubtree(cur, key);
                break;
            } else
                cur = cur->right_child;
        }
    }
}*/
BSTNode* Remove(BSTNode* root, Key key) {
    if (root == NULL)return NULL;
    if (key < root->key)// The key is at the left subtree.
        root->left_child = Remove(root->left_child, key);
    else if (key > root->key)// The key is at the right subtree.
            root->right_child = Remove(root->right_child, key);
    else { // The root is the node to be removed.
            BSTNode *cur = root;
            // Case 1: No child node
            if (root->left_child == NULL && root->right_child == NULL){
                DestroyNode(cur);
                root = NULL;
            } // Case 2: One child code
            else if (root->left_child == NULL || root->right_child == NULL) {
                if (root->left_child != NULL) {
                    // Replace the root with its child node.
                    root = root->left_child;
                    DestroyNode(cur);
                } else {
                    root = root->right_child;
                    DestroyNode(cur);
                }
            }else { // The root has two child nodes.
                // Find the inorder successor of the root.
                cur = cur->right_child;
                while (cur->left_child != NULL)
                    cur = cur->left_child;
                // Copy the successor to the root for deleting the root.
                root->key = cur->key;
                // Delete the inorder successor.
                root->right_child = Remove(root->right_child, cur->key);
            }
        }
    return root;
}
//version of lterative
/*BSTNode* Remove(BSTNode* root, Key key) {
    BSTNode* cur = root, *parent = NULL;
    // Find the current node and its parent node.
    while (cur != NULL && cur->key != key)
    {
        parent = cur; // Find the parent node for update.
        if (cur->key > key)
            cur = cur->left_child;
        else
            cur = cur->right_child;
    }
    if (cur == NULL) exit(1);
    
    if (cur->left_child == NULL && cur->right_child == NULL) {
        if (parent != NULL) {
            // Remove the current node depending on its position.
            if (parent->left_child == cur)
                parent->left_child = NULL;
            else
                parent->right_child = NULL;
        }
        else
            root = NULL;
    }else if (cur->left_child == NULL || cur->right_child == NULL)
    {
        BSTNode* child;
        // Find the child node.
        if (cur->left_child != NULL)
            child = cur->left_child;
        else
            child = cur->right_child;
        if (parent != NULL) { // Update the parent node.
            if (parent->left_child == cur)
                parent->left_child = child;
            else
                parent->right_child = child;
        }
        else {
            // Because the root is removed, replace it with its child.
            root = child;
        }
    }
    else {
        BSTNode* succ_parent = cur, *succ = cur->right_child;
        // Find the successor (left-most node of the current node.)
        while (succ->left_child != NULL) {
            succ_parent = succ;
            succ = succ->left_child;
        }
        // If the successor has a child node
        //connect the child node to its parent node.
        if (succ_parent->right_child == succ)
            // The successor is the direct right child node.
            succ_parent->right_child = succ->right_child;
        else
            succ_parent->left_child = succ->right_child;
        // Copy the key of the successor to that of the current node.
        cur->key = succ->key, cur = succ;// Change the current node to remove the successor.
    }
    DestroyNode(cur);
    return root;
}*/
BSTNode* CreateNode(Key key){
    BSTNode* root = (BSTNode*)malloc(sizeof(BSTNode));
    root->key = key;
    root->left_child = NULL;
    root->right_child = NULL;
    return root;
}
void DestroyNode(BSTNode* node)
{
    free(node);
}
void CreateLeftSubtree(BSTNode* root, Key key) {
    if (root->left_child != NULL) exit(1);
    root->left_child = CreateNode(key);
}
void CreateRightSubtree(BSTNode* root, Key key) {
    if (root->right_child != NULL) exit(1);
    root->right_child = CreateNode(key);
}
void inorder(BSTNode* root){
    if(root != NULL){
        inorder(root->left_child);
        printf("%d ", root->key);
        inorder(root->right_child);
    }
}
