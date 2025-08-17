#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int key;
    struct node *left,*right;
}node;

node* create(node *root,int val){
    if((root)==NULL){
        (root)=(node*)malloc(sizeof(node));
        (root)->key=val;
        (root)->left=NULL;
        (root)->right=NULL;
        return root;
    }
    else{
        node* check=(root);
        if(check->key>val){
            root->left=create(root->left,val);
        }
        else{
            root->right=create(root->right,val);
        }
    }
    return root;
}

void search(node* root,int val){
    if(root==NULL){
        printf("key not available in the tree\n");
    }
    else{
        if(root->key==val){
            printf("key available in the tree\n");
        }
        else if(root->key<val){
            search(root->right,val);
        }
        else{
            search(root->left,val);
        }
    }
}

node* inorderSucc(node* root){
    node* curr=root;
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
node* deleteInBST(node* root,int val){
    if(val<root->key){
        root->left=deleteInBST(root->left,val);
    }
    else if(val>root->key){
        root->right=deleteInBST(root->right,val);
    }
    else{
        if(root->left==NULL){
            node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            node* temp=root->left;
            free(root);
            return temp;
        }
        else{
            node* temp=inorderSucc(root->right);
            root->key=temp->key;
            root->right=deleteInBST(root->right,temp->key);
        }
    }
    return root;
}

void LeafNodes(node* root,int *count){
    if(root==NULL){
        return;
    }
    
    if(root->left==NULL && root->right==NULL){
        (*count)++;
        return;
    }

    if(root->left!=NULL){
        LeafNodes(root->left,count);
    }
    if(root->right!=NULL){
        LeafNodes(root->right,count);
    }
}

int Height(node* root){
    if(root==NULL){
        return 0;
    }
    int left=Height(root->left);
    int right=Height(root->right);
    if(left<right){
        return right+1; 
    }
    return left+1;
}

void total(node* root,int *nodecount){
    if(root==NULL){
        return;
    }
    (*nodecount)++;
    total(root->left,nodecount);
    total(root->right,nodecount);
}

void KthLargest(node* root,int* k,int* value){

    if(*k){    
        if(root==NULL){
            return;
        }
        KthLargest(root->right,k,value);
        (*k)--;
        if((*k)==0){
            (*value)=root->key;
        }
        KthLargest(root->left,k,value);
    }
}

int main(){
    node* root=NULL;
    int n;
    while(n!=-1){
        printf("enter a key(enter -1 to stop insertion)\n");
        scanf("%d",&n);
        if(n!=-1){
            root=create(root,n);
        }
        else{
            printf("insertion stopped\n");
        }
    }
    int a;
    n=0;
    printf("1->Search a key     2->Delete a node\n3->Find number of leaf nodes      4->Height of the tree\n5->Total nodes from right hand side of root node     6->Kth largest element\n0->To stop\n");
    scanf("%d",&a);
    while(a){
        switch(a){
            case 0:{
                break;
            }
            case 1:{
                printf("enter a key to search\n");
                scanf("%d",&n);
                search(root,n);
                break;
            }
            case 2:{
                int x;
                printf("enter the value to be deleted\n");
                scanf("%d",&x);
                root=deleteInBST(root,x);
                printf("value deleted\n");
                break;
            }
            case 3:{
                int count=0;
                LeafNodes(root,&count);
                printf("Total number of leafnodes are %d\n",count);
                break;
            }
            case 4:{
                printf("Height of the given tree is %d\n",Height(root)-1);
                break;
            }
            case 5:{
                int nodecount=0;
                total(root->right,&nodecount);
                printf("Total number of nodes in the right hand side of given tree is %d\n",nodecount);
                break;
            }
            case 6:{
                int k=0,value=0;
                printf("Enter value of k to find kth largest element\n");
                scanf("%d",&k);
                KthLargest(root,&k,&value);
                printf("kth largest element in given tree is %d\n",value);
                break;
            }
            default:{
                printf("not a valid choice\n");
                break;
            }
        }
        printf("enter new choice\n");
        scanf("%d",&a);
    }
    return 0;
}