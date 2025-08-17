#include<stdio.h>
#define MAX 10

void enqueue(int queue[],int *front,int *rear,int value){
    if((*(rear)+1) % MAX==*front){
        printf("queue is full");
    }
    else{
        *rear=(*(rear)+1)%MAX;
        if(*(front)==-1){
            *front=0;
        }
        queue[*rear]=value;
    }
}

int dequeue(int queue[],int *front ,int *rear){
    if(*front==*rear){
        printf("queue is empty");
        return -1;
    }
    else{
        (*front)++;
        return queue[*front];
    }
}

void display(int queue[],int front,int rear){
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main(){
    int queue[MAX],front=-1,rear=-1,n,val;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter the values \n");
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        enqueue(queue,&front,&rear,val);
    }
    display(queue,front,rear);
    printf("deleted value is %d \n",dequeue(queue,&front,&rear));
    display(queue,front,rear);
    enqueue(queue,&front,&rear,6);
    display(queue,front,rear);
    return 0;
}