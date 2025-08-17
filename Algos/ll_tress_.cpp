// #include<iostream>
// using namespace std;

// struct node{
//     int data;
//     struct node *left;
//     struct node *right;
// };

// int main(){
//     struct node *p;
//     p = (struct node *)malloc(sizeof(struct node));
//     p->data=1;
//     p->left=NULL;
//     p->right=NULL;

//     struct node *p2;
//     p2 = (struct node *)malloc(sizeof(struct node));
//     p2->left=NULL;
//     p2->right=NULL;

//     struct node *p3;
//     p3 = (struct node *)malloc(sizeof(struct node));
//     p3->left=NULL;
//     p3->right=NULL;

//     return 0;
// }






// #include<iostream>
// using namespace std;

// struct node{
//     int data;
//     struct node *left;
//     struct node *right;
// };

// struct node *CreateNode(int data){
//     struct node *nod;
//     nod=(struct node *)malloc(sizeof(struct node));
//     nod->data=data;
//     nod->left=NULL;
//     nod->right=NULL;
//     return nod;
// }

// int main(){
//     struct node *p = CreateNode(4);
//     struct node *p1 = CreateNode(1);
//     struct node *p2 = CreateNode(6);
//     struct node *p3 = CreateNode(5);
//     struct node *p4 = CreateNode(2);

//     p->left=p1;
//     p->right=p2;
//     p1->left=p3;
//     p1->right=p4;
//     return 0;
// }

