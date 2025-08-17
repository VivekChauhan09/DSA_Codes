#include<stdio.h>
#define MAX 10

void enqueue(int queue[],int *front,int *rear,int value){
	if(*rear>=MAX-1){
 		printf("Queue is full!");
 	}
	else{
		if(*front==-1){
			(*front)++;
			(*rear)++;
		}
 		(*rear)++;
 		queue[*rear]=value;
	}
}
int dequeue(int queue[],int *front,int *rear){
 	if(*front==*rear){
 		printf("Queue is empty!");
 		return -1;
 	}
	else{
 		(*front)++;
 		return queue[*front];
 	}
}

void display(int queue[],int front,int rear){
 	for(int i=front+1;i<=rear;i++){
 		printf("%d ",queue[i]);
 	}
    printf("\n");
}

int main(){
 	int queue[MAX],i,n,value;
    printf("Enter the no. of elements : ");
 	scanf("%d",&n);
 	int front=-1,rear=-1;
 	printf("Enter the elements \n");
 	for(i=0;i<n;i++){
		int val;
 		scanf("%d",&val);
 		enqueue(queue,&front,&rear,val);
 	}
 	printf("Queue contents : ");
 	display(queue,front,rear);
 	printf("Deleted item is : %d\n",dequeue(queue,&front,&rear));
 	printf("Updated queue contents : ");
 	display(queue,front,rear);
 	return 0;
}