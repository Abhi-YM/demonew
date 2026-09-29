#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* BuildTree()
{
    int data;

    printf("Enter data: ");
    scanf("%d", &data);

    if (data == -1)
        return NULL;

    struct Node *node = (struct Node*)malloc(sizeof(struct Node));

    node->data = data;

    printf("Enter left child of %d:\n", data);
    node->left = BuildTree();

    printf("Enter right child of %d:\n", data);
    node->right = BuildTree();

    return node;
}

int main()
{
    struct Node *root;

    root = BuildTree();

    return 0;
}