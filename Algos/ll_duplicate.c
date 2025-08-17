#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * left,*right;
};

struct node *create(struct node *root,int val){
    int n;
    if(root==NULL){
        root=(struct node *)malloc(sizeof(struct node));
        root->data=val;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    else{
        struct node *check=root;
        if(root->data!=val){
            if(val<check->data){    
                root->left=create(root->left,val);
            }
            else{
                root->right=create(root->right,val);
            }
        }
        else{
            printf("Duplicate Value \n");
            printf("enter another data : ");
            scanf("%d",&n);
            create(root,n);
        }
    }
    return root;
};


void inorder(struct node * root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void search(struct node *root,int key){
    if (root==NULL){
        printf("Key not found \n");
    }
    else{
        if(key==root->data){
            printf("Key found \n");
        }
        else if(key<root->data){
            search(root->left,key);
        }
        else{
            search(root->right,key);
        }
    }
}

void LeafNode(struct node *root,int *count){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        (*count)++;
        return;
    }
    if(root->left!=NULL){
        LeafNode(root->left,count);
    }
    if(root->right!=NULL){
        LeafNode(root->right,count);
    }
}

int Height(struct node *root){
    if(root==NULL){
        return 0;
    }
    int left=Height(root->left);
    int right=Height(root->right);
    if(left<right)
        return right+1;
    return left+1;
}

int main(){
    struct node * root=NULL;
    int num,key;
    printf("Enter the number of data u want to insert in a bst : ");
    scanf("%d",&num);
    for (int i=0;i<num;i++){
        int val;
        printf("Enter the value : ");
        scanf("%d",&val);
        root=create(root,val);
    }

    printf("Sorted bst is : ");
    inorder(root);

    printf("Enter a key to search : ");
    scanf("%d",&key);
    search(root,key);

    int count=0;
    LeafNode(root,&count);
    printf("total number of leaf nodes are %d ",count);

    printf("height is %d ",Height(root)-1);

    return 0;
}