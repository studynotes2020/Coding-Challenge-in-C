#include <stdio.h>
#include "linkedList.h"

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    return prev;
}

struct ListNode* reverseList2(struct ListNode* head){
    if (head == NULL || head->next == NULL) return head;
    struct ListNode* p = reverseList2(head->next);
    head->next->next = head;
    head->next = NULL;
    return p;
}


int main() {
    int A[] = {2,8,4,3,7};
    int len = sizeof(A)/sizeof(int);
    struct ListNode* head = createLinkedList(A, len);
    printNode(head);
    head = reverseList2(head);
    printNode(head);

    return 0;
}