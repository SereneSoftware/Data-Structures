#include <stdio.h>
#include <stdlib.h>

struct Cqueue {
  int size;
  int f;
  int r;
  int *arr;
};

int IsEmpty(struct Cqueue* ptr) {
    if (ptr->f == ptr->r) {
        return 1;
    }
    else {
        return 0;
    }
}    
    
int IsFull(struct Cqueue* ptr) {
    if ((ptr->r+1)%ptr->size == ptr->f) {
        return 1;
    }
    else {
        return 0;
    }
} 

void enqueue(int x, struct Cqueue* ptr) {
    if (IsFull(ptr)) {
        printf("The queue is overlfow\n");
    }
    else {
        ptr->r = (ptr->r+1)%ptr->size;
        ptr->arr[ptr->r] = x;
    }
}

void dequeue(struct Cqueue *ptr) {
    if (IsEmpty(ptr)) {
        printf("The queue is underflow\n");
    }
    else {
        ptr->f = (ptr->f+1)%ptr->size;
        int v = ptr->arr[ptr->f];
        printf("The value deleted is %d", v);
    }
}  
int main() {
    
  struct Cqueue *q = (struct Cqueue *)malloc(sizeof(struct Cqueue));
    q->size = 8;
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