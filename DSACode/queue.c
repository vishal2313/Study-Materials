#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;

};

int isFull(struct queue*q){
    if(q->r==q->size-1){
     return 1;
    }
    return 0;
}

int isEmpty(struct queue *q){
    if(q->f==q->r){
        return 1;
    }
        return 0;
}

void enqueue(struct queue* q,int val){
    if(isFull(q)){
        printf("the queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r]=val;

    }
}

 int dequeue(struct queue* q){
    int a=-1;             
    if(isEmpty(q)){
        printf("the queue is empty\n");
    }
    else
    {
        q->f++;
        a=q->arr[q->f];

    }
    return a;
}

int main(){
 struct queue q;
 q.size=5;
 q.f=q.r=-1;
 q.arr=(int*)malloc(q.size*sizeof(int));
 enqueue(&q,12);
 enqueue(&q,27);
 enqueue(&q,2);
 enqueue(&q,4);
 
 if(isFull(&q)){
    printf("the queue is full\n");
 }

 printf("the dequeued element is : %d\n",dequeue(&q));
 printf("the dequeued element is : %d\n",dequeue(&q));
 printf("the dequeued element is : %d\n",dequeue(&q));

 if(isEmpty(&q)){
    printf("the queue is empty\n");
 }

return 0;
}