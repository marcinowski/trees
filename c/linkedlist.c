#include <stdio.h>
#include <stdlib.h>
#include "types.h"

linkedList *getLinkedList() {
    linkedList *root = malloc(sizeof(linkedList));
    root->value = 0;
    root->prev = NULL;
    root->next = NULL;
    return root;
}

linkedList *copyList(linkedList *root) {
    if (root == NULL) {
        return NULL;
    }
    linkedList *copy = getLinkedList();
    while (root != NULL) {
        addValueToList(copy, root->value);
        root = root->next;
    }
    return copy;
}

void destroyList(linkedList *root) {
    if (root == NULL) {
      return;
    }
    while (root->next != NULL) {
      printf("Destroying %d\n", root->value);
      root = root->next;
      free(root->prev);
    }
    printf("Destroying %d\n", root->value);
    free(root);
}

void addToListRec(linkedList *root, int value) {
    if (root == NULL) {
        return;
    }
    if (root->value == 0) {
        root->value = value;
        return;
    }
    if (root->next == NULL) {
        linkedList *next = getLinkedList();
        next->value = value;
        next->prev = root;
        root->next = next;
    } else {
        addToListRec(root->next, value);
    }
}

linkedList *joinLists(linkedList *first, linkedList *last) {
    if (first == NULL) {
        return last;
    }
    if (last == NULL) {
        return first;
    }
    linkedList *cfirst = copyList(first);
    linkedList *clast = copyList(last);
    linkedList *start = cfirst;
    while (cfirst->next != NULL) {
        cfirst = cfirst->next;
    }
    cfirst->next = clast;
    clast->prev = cfirst;
    return start;
}

linkedList *addValueToList(linkedList* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    linkedList *start = root;
    while (root->next != NULL) {
        root = root->next;
    }
    if (root->value == 0) {
        root->value = value;
    } else {
        linkedList *next = getLinkedList();
        next->value = value;
        next->prev = root;
        root->next = next;
    }
    return start;
}

void addToListLoop(linkedList *root, int argc, int *argv) {
    if (root == NULL) {
        return;
    }
    while (root->next != NULL) {
        root = root->next;
    }
    if (root->value == 0) {
        root->value = argv[0];
        argv += 1;
        argc--;
    }
    for (int i=0; i<argc; i++) {
        int value = argv[i];
        linkedList *next = getLinkedList();
        next->value = value;
        next->prev = root;
        root->next = next;
        root = root->next;
    }
}

void removeFromList(linkedList *root, int value) {
    if (root == NULL) {
        return;
    }
    while (root->value != value) {
        root = root->next;
        if (root == NULL) {
            return;
        }
    }
    linkedList *prev = root->prev;
    linkedList *next = root->next;
    next->prev = prev;
    prev->next = next;
    free(root);
}

int listLength(linkedList *root) {
    int length = 0;
    while (root != NULL) {
        length++;
        root = root->next;
    }
    return length;
}

void printList(linkedList *root) {
  while (root != NULL) {
      printf("Value %d\n", root->value);
      root = root->next;
  }
}
