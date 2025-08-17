//using STL
#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int freq;
    char data;
    struct node *left,*right;
    node (char data,int freq)
    {
        this->data=data;
        this->freq=freq;
        this->left=NULL;
        this->right=NULL;
    }
}node;

struct compare 
{
    bool operator () (node *a,node *b)
    {
        return a->freq > b->freq;
    }
};

void printCode (node *root,string str)
{
    if (root->data!='$' )
    {
        cout<<root->data << " : "<<str<<endl;
        return;
    } 
printCode(root->left,str+"0");
printCode(root->right,str+"1");
}

void huffmanCode(char data[],int freq[],int n)
    {
        priority_queue <node *,vector<node *>,compare> pq;
        for (int i=0;i<n;i++)
    {
    pq.push(new node(data[i],freq[i]));
}
    while (pq.size()!=1)
    {
        node *left=pq.top();
        pq.pop();
        node *right=pq.top();
        pq.pop();
        node *root = new node('$',left->freq+right->freq);
        root->left=left;
        root->right=right;
        pq.push(root);
    }
    printCode(pq.top(),"");
}

int main()
{
    char data[]={'a','b','c','d','e','f'};
    int freq[]= {55,20,12,25,30,8};
    huffmanCode(data,freq,6);
}