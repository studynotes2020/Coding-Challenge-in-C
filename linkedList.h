#ifndef C_LINKEDLIST_H
#define C_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void printNode(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

struct ListNode* createLinkedList(const int* A, int len) {
    struct ListNode* head = (struct ListNode*) malloc(sizeof(struct ListNode));
    head->val = A[0];
    struct ListNode* tail = head;
    for (int i = 1; i < len; i++) {
        tail->next = malloc(sizeof(struct ListNode));
        tail = tail->next;
        tail->val = A[i];
    }
    tail->next = NULL;
    return head;
}

#endif //C_LINKEDLIST_H
