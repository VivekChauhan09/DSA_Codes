#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *CreateNode(int data){
    struct node *nod;
    nod=(struct node *)malloc(sizeof(struct node));
    nod->data=data;
    nod->left=NULL;
    nod->right=NULL;
    return nod;
}

void preorder(struct node * root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node * root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);

}

void inorder(struct node * root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main(){
    struct node *p = CreateNode(4);
    struct node *p1 = CreateNode(1);
    struct node *p2 = CreateNode(6);
    struct node *p3 = CreateNode(5);
    struct node *p4 = CreateNode(2);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    printf("The preorder is : ");
    preorder(p);
    printf("\n");
    printf("The postorder is : ");
    postorder(p);
    printf("\n");
    printf("The inorder is : ");
    inorder(p);

    return 0;
}
