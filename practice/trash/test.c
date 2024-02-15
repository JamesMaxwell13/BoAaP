#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printSpiral(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Node* stack1[100];
    struct Node* stack2[100];
    int top1 = -1;
    int top2 = -1;
    stack1[++top1] = root;
    while (top1 >= 0 || top2 >= 0) {
        while (top1 >= 0) {
            struct Node* node = stack1[top1--];
            printf("%d ", node->data);
            if (node->right != NULL) {
                stack2[++top2] = node->right;
            }
            if (node->left != NULL) {
                stack2[++top2] = node->left;
            }
        }
        while (top2 >= 0) {
            struct Node* node = stack2[top2--];
            printf("%d ", node->data);
            if (node->left != NULL) {
                stack1[++top1] = node->left;
            }
            if (node->right != NULL) {
                stack1[++top1] = node->right;
            }
        }
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    printf("Spiral Order traversal of binary tree is \n");
    printSpiral(root);
    return 0;
}
