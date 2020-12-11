#ifndef C_QUEUE_H
#define C_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct Queue {
    struct ListNode *front;
    struct ListNode *rear;
};

struct ListNode* newNode(int k)
{
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val = k;
    temp->next = NULL;
    return temp;
}

struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue* q, int k)
{
    // Create a new LL node
    struct ListNode* temp = newNode(k);

    // If queue is empty, then new node is front and rear both
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    // Add the new node at the end of queue and change rear
    q->rear->next = temp;
    q->rear = temp;
}

int deQueue(struct Queue* q)
{
    // If queue is empty, return NULL.
    if (q->front == NULL)
        return NULL;

    // Store previous front and move front one node ahead
    struct ListNode* temp = q->front;
    int n = q->front->val;
    q->front = q->front->next;

    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return n;
}

#endif //C_QUEUE_H
