#include <stdio.h>
#include <stdlib.h>

typedef struct linkedList {
    int value;
    struct linkedList* prev;
    struct linkedList* next;
} linkedList;

linkedList *getLinkedList() {
    linkedList *root = malloc(sizeof(linkedList));
    root->value = 0;
    root->prev = NULL;
    root->next = NULL;
    return root;
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

int main(int argc, char const *argv[]) {
    linkedList *list = getLinkedList();
    addToListRec(list, 1);
    int *p;
    int vars[5] = {2, 3, 4, 5, 6};
    p = vars;
    addToListLoop(list, 5, p);
    printList(list);
    printf("Length: %d\n", listLength(list));
    removeFromList(list, 3);
    printList(list);
    printf("Length: %d\n", listLength(list));
    destroyList(list);
    return 0;
}
