#include <stdio.h>
#include <stdlib.h>

struct queue {
  int size;
  int f;
  int r;
  int *arr;
};

int IsEmpty(struct queue* ptr) {
    if (ptr->f == ptr->r) {
        return 1;
    }
    else {
        return 0;
    }
}    
    
int IsFull(struct queue* ptr) {
    if (ptr-> r == ptr->size-1) {
        return 1;
    }
    else {
        return 0;
    }
} 

void enqueue(int x, struct queue* ptr) {
    if (IsFull(ptr)) {
        printf("The queue is overlfow\n");
    }
    else {
        ptr->r = ptr->r+1;
        ptr->arr[ptr->r] = x;
    }
}

void dequeue(struct queue *ptr) {
    if (IsEmpty(ptr)) {
        printf("The queue is underflow\n");
    }
    else {
        ptr->f = ptr->f+1;
        int v = ptr->arr[ptr->f];
        printf("The value deleted is %d", v);
    }
}  
int main() {
    
  struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 1;
    q->f=-1;
    q->r = -1;
    q->arr = (int*) malloc (q->size * sizeof(int)); 
    printf("%d\n", IsEmpty(q));
    enqueue(910, q);
    enqueue(20, q);
    printf("%d\n", IsEmpty(q));
    dequeue(q);
  return 0;
  
}  