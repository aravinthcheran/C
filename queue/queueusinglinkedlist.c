#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, int data) {
    struct Node* temp = newNode(data);

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

void dequeue(struct Queue* q) {
    if (q->front == NULL)
        return;

    struct Node* temp = q->front;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

void display(struct Queue* q) {
    struct Node* temp = q->front;
    while(temp != NULL) {
        if(temp->next != NULL)
            printf("%d->", temp->data);
        else
            printf("%d", temp->data);
        temp = temp->next;
    }
    if(q->front == NULL)
        printf("Queue is empty\n");
    else
        printf("\n");
}

int main() {
    struct Queue* q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    dequeue(q);
    display(q);
    enqueue(q, 4);
    display(q);
    return 0;
}