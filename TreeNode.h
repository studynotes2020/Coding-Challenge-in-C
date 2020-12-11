#ifndef C_TREENODE_H
#define C_TREENODE_H

#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* BuildTree(struct TreeNode* A) {
    struct TreeNode* root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    root->val = A[0].val;

}

void printLevelOrder() {
    struct TreeNode* res = (struct TreeNode*) malloc(sizeof(struct TreeNode));
}

#endif //C_TREENODE_H
