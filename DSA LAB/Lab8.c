#include <stdio.h>
#include <stdlib.h>

struct node {
    float data;
    struct node *lchild, *rchild;
};

struct node* createNode(float value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->lchild = newNode->rchild = NULL;
    return newNode;
}

struct node* insert(struct node* root, float value) {
    if (root == NULL) return createNode(value);
    if (value < root->data)
        root->lchild = insert(root->lchild, value);
    else if (value > root->data)
        root->rchild = insert(root->rchild, value);
    return root;
}

struct node* insertIterative(struct node* root, float value) {
    struct node* newNode = createNode(value);
    if (root == NULL) {
        return newNode;
    }
   
    struct node* parent = NULL;
    struct node* current = root;

    while (current != NULL) {
        parent = current;
        if (value < current->data)
            current = current->lchild;
        else if (value > current->data)
            current = current->rchild;
        else {
            free(newNode);
            return root;
        }
    }

    if (value < parent->data)
        parent->lchild = newNode;
    else
        parent->rchild = newNode;

    return root;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%.2f ", root->data);
        inorder(root->rchild);
    }
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%.2f ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%.2f ", root->data);
    }
}

int main() {
    struct node* root = NULL;
    int choice;
    float value;

    while (1) {
        printf("\n1. Insert recursively\n2. Insert iteratively\n3. Inorder\n4. Preorder\n5. Postorder\n5.enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert recursively: ");
                scanf("%f", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter value to insert iteratively: ");
                scanf("%f", &value);
                root = insertIterative(root, value);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                preorder(root);
                break;
            case 5:
                postorder(root);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
