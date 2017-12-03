#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "types.h"

void testToList() {
    int *p;
    int vars[5] = {2, 3, 4, 5, 6};
    p = vars;
    binTree *root = fromList(5, p);
    linkedList *list = toList(root);
    assert(listLength(list) == 5);
    assert(list->value == 2);
}

int main(int argc, char const *argv[]) {
    printf("Running tests ");
    printf(".");
    testToList();
    printf("\n");
    printf("All tests passed!\n");
}
