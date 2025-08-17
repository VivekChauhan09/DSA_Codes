#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node * createNode(int value){
    struct node * newnode =(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node *insert(struct node *root,int value){
    if (root==NULL){
        return createNode(value);
    }
    if (value<root->data){
        root->left=insert(root->left,value);
    }
    else if (value>root->data){
        root->right=insert(root->right,value);
    }

    return root;
}

struct node* findMinnode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct node* deletenode(struct node* root, int value) {
    if (root == NULL) {
        return root;
    }
    if (value < root->data) {
        root->left = deletenode(root->left, value);
    } 
    else if (value > root->data) {
        root->right = deletenode(root->right, value);
    } 
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = findMinnode(root->right);
 
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}

void findMinMax(struct node* root) {
    while (root->left != NULL) {
        root = root->left;
    }    printf("Smallest info : %d\n", root->data);

    while (root->right != NULL) {
        root = root->right;
    }
    printf("Largest info : %d\n", root->data);
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main() {
    struct node* root = NULL;

    root = insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    insert(root, 60);
    insert(root, 70);

    findMinMax(root);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");
    
    root = deletenode(root, 20); 
    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n");
    return 0;
}

