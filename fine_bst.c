/* MEMBER 4: DEV KUMAR - C BINARY SEARCH TREE FOR FINE RECORDS.
   Uses a struct, pointers, recursion and inorder traversal from the BST topics covered so far. */
#include <stdio.h>
#include <stdlib.h>

struct FineNode {
    int vehicleID;
    int totalFine;
    struct FineNode *left;
    struct FineNode *right;
};

static struct FineNode *root = NULL;

static struct FineNode* insertFine(struct FineNode *node, int id, int amount) {
    if (node == NULL) {
        struct FineNode *newNode = (struct FineNode*)malloc(sizeof(struct FineNode));
        if (newNode == NULL) return NULL;
        newNode->vehicleID = id;
        newNode->totalFine = amount;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (id < node->vehicleID) {
        node->left = insertFine(node->left, id, amount);
    } else if (id > node->vehicleID) {
        node->right = insertFine(node->right, id, amount);
    } else {
        node->totalFine += amount;
    }
    return node;
}

void addFineRecord(int vehicleID, int amount) {
    if (amount <= 0) return;
    root = insertFine(root, vehicleID, amount);
}

static void printInOrder(struct FineNode *node) {
    if (node == NULL) return;
    printInOrder(node->left);
    printf("Vehicle ID: %d | Total fine: Rs. %d\n", node->vehicleID, node->totalFine);
    printInOrder(node->right);
}

void displayFineRecords(void) {
    if (root == NULL) {
        printf("No fine records.\n");
        return;
    }
    printf("Fine records in ascending vehicle ID order:\n");
    printInOrder(root);
}
