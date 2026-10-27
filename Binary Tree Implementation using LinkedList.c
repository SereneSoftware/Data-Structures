
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *CreateNode(int data) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));

    if (n == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void PreOrderTraversal(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }
}

void InOrderTraversal(struct Node *root) {
    if (root != NULL) {
        InOrderTraversal(root->left);
        printf("%d ", root->data);
        InOrderTraversal(root->right);
    }
}

void PostOrderTraversal(struct Node *root) {
    if (root != NULL) {
        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

struct Node *Search(struct Node *root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == key) {
        return root;
    }

    if (key < root->data) {
        return Search(root->left, key);
    }

    return Search(root->right, key);
}

int main(void) {
    struct Node *root = CreateNode(7);
    struct Node *p1 = CreateNode(4);
    struct Node *p2 = CreateNode(10);
    struct Node *p3 = CreateNode(9);
    struct Node *p4 = CreateNode(3);
    struct Node *p5 = CreateNode(13);

    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p2->left = p4;
    p2->right = p5;

    printf("Preorder Traversal: ");
    PreOrderTraversal(root);
    printf("\n");

    printf("Inorder Traversal: ");
    InOrderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    PostOrderTraversal(root);
    printf("\n");

    int key = 9;
    struct Node *result = Search(root, key);

    if (result != NULL) {
        printf("%d found in the tree.\n", key);
    } else {
        printf("%d not found in the tree.\n", key);
    }

    return 0;
}
