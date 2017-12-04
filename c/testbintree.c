#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "types.h"

void testToListEasy() {
    printf("testToListEasy - running.\n");
    binTree *root = getTree();
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    linkedList *list = toList(root);
    printList(list);
    assert(listLength(list) == 3);
    assert(list->value == 1);
    printf("testToListEasy - passed.\n");
}

void testToListHard() {
    printf("testToListHard - running.\n");
    int *p;
    int vars[5] = {2, 3, 4, 5, 6};
    p = vars;
    binTree *root = fromList(5, p);
    linkedList *list = toList(root);
    printList(list);
    assert(listLength(list) == 5);
    assert(list->value == 2);
    printf("testToListHard - passed.\n");
}

int main(int argc, char const *argv[]) {
    printf("Running tests..\n");
    testToListEasy();
    testToListHard();
    printf("All tests passed!\n");
}
