#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void Traversal(struct Node *ptr) {
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node* InsertAtBegin(int data, struct Node* head) {
    struct Node *ptr = (struct Node*) malloc (sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}

struct Node* DeleteByValue(struct Node *head, int val) {
    struct Node * p = head;
    struct Node * q = head->next;

    while(p->data != val && p->next != NULL) {
        p=p->next;
    }
    if (p->data == val) {
        p->next = q->next;
        free(q);
    }
}

int main() {
    struct Node* head = (struct Node*) malloc (sizeof(struct Node));
    struct Node * first = (struct Node*) malloc (sizeof(struct Node));
    struct Node * second = (struct Node*) malloc (sizeof(struct Node));
    
    head->data=45;
    head->next=first;
    
    first->data=90;
    first->next=second;
    
    second->data=60;
    second->next=NULL;
    
    head = InsertAtBegin(78, head);
    Traversal(head);
    DeleteByValue(head, 90);
    
    return 0;
}