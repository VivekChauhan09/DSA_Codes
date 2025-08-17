#include<stdio.h>
#include<stdlib.h>


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
};


void inorder(struct node * root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int isBst(struct node *root){
    static struct node *prev=NULL;
    if(root!=NULL){
        if (!isBst(root->left)){
            return 0;
        }
        if (prev!=NULL && root->data<=prev->data){
            return 0;
        }
        prev=root;
        return isBst(root->right);
    }
    else{
        return 1;
    }
}


// struct node *search(struct node *root,int key){
//     if(root==NULL){
//         return NULL;
//     }
//     if(key==root->data){
//         return root;
//     }
//     else if(key<root->data){
//         return search(root->left,key);
//     }
//     else{
//          return search(root->right,key);
//     }
// }

struct node *searchIter(struct node * root,int key){
    while(root!=NULL){
        if(key==root->data){
            return root;
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return NULL;
}

int main(){
    struct node *p = CreateNode(5);
    struct node *p1 = CreateNode(3);
    struct node *p2 = CreateNode(6);
    struct node *p3 = CreateNode(1);
    struct node *p4 = CreateNode(4);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    printf("The inorder is : ");
    inorder(p);
    printf("\n"); 
    if(isBst(p)==1){
        printf("It is a Bst");
    }
    else{
        printf("It is not a bst");
    }
    printf("\n");


    // struct node *q=search(p,1);
    // if(q!=NULL){
    //     printf("Found %d ",q->data);
    // }
    // else{
    //     printf("Not found");
    // }

    struct node *n=searchIter(p,1);
    if(n!=NULL){
        printf("found  %d ",n->data);
    }
    else{
        printf("Element not found ");
    }
    return 0;
}