#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct binTree {
    int value;
    struct binTree* leftChild;
    struct binTree* rightChild;
} binTree;

binTree *getTree () {
    binTree *a = malloc(sizeof(binTree));;
    a->value = 0;
    a->rightChild = NULL;
    a->leftChild = NULL;
    return a;
}

linkedList *a = getLinkedList();

void destroyTree(binTree *root) {
    if (root == NULL) {
        return;
    }
    destroyTree(root->leftChild);
    destroyTree(root->rightChild);
    printf("Destroying %d\n", root->value);
    free(root);
    return;
}

void insert(binTree *root, int value) {
    if (root->value == 0) {
        printf("New child populated with %d\n", value);
        root->value = value;
        return;
    }
    if (root->value < value) {
        if (root->rightChild == NULL) {
            printf("Right child created\n");
            root->rightChild = getTree();
        }
        printf("Populating right child with: %d\n", value);
        insert(root->rightChild, value);
    } else {
        if (root->leftChild == NULL) {
            printf("Left child created\n");
            root->leftChild = getTree();
        }
        printf("Populating left child with: %d\n", value);
        insert(root->leftChild, value);
    }
    return;
}

void insertMany(binTree *root, int argsc, int *args) {
    for (int i=0; i < argsc; i++) {
        insert(root, args[i]);
    }
}

int search(binTree *root, int value) {
    if (root == NULL) {
        return 0;
    }
    if (root->value == value) {
        printf ("Value %d found!\n", value);
        return 1;
    } else if (root->value > value) {
        return search(root->leftChild, value);
    } else if (root->value < value) {
        return search(root->rightChild, value);
    } else {
        return 0;
    }
}

int length(binTree *root) {
    if (root == NULL) {
        return 0;
    }
    int len = 1;
    len += length(root->leftChild);
    len += length(root->rightChild);
    return len;
}

int depth(binTree *root) {
    if (root == NULL) {
        return 0;
    }
    int dep = 1;
    int lc = depth(root->leftChild);
    int rc = depth(root->rightChild);
    dep += lc > rc ? lc : rc;
    return dep;
}

int minimum(binTree *root) {
    if (root == NULL) {
        return -1;
    }
    if (root->leftChild != NULL) {
        return minimum(root->leftChild);
    } else {
        return root->value;
    }
}

int maximum(binTree *root) {
    if (root == NULL) {
        return -1;
    }
    if (root->rightChild != NULL) {
        return maximum(root->rightChild);
    } else {
        return root->value;
    }
}

void removeFromTree(binTree *root, int value) {
    if (root == NULL) {
        return;
    }
    if (root->value == value) {
        if (root->leftChild != NULL || root->rightChild != NULL) {
            int ldep = depth(root->leftChild);
            int rdep = depth(root->rightChild);
            if (rdep > ldep || root->leftChild == NULL) {
                int val = minimum(root->rightChild);
                root->value = val;
                removeFromTree(root->rightChild, val);
            } else {
                int val = maximum(root->leftChild);
                root->value = val;
                removeFromTree(root->leftChild, val);
            }
        } else {
            root->value = 0;
        }
    } else if (root->value > value) {
        removeFromTree(root->leftChild, value);
    } else if (root->value < value) {
        removeFromTree(root->rightChild, value);
    }
    if (root->leftChild != NULL && root->leftChild->value == 0) {
        free(root->leftChild);
        root->leftChild = NULL;
    }
    if (root->rightChild != NULL && root->rightChild->value == 0) {
        free(root->rightChild);
        root->rightChild = NULL;
    }
    return;
}

binTree *fromList(int len, int *args) {
    int middle = (int)len/2;
    int value = *(args+middle);
    binTree *root = getTree();
    insert(root, value);
    int leftLen = middle;
    int rightLen = len - middle - 1;
    if (leftLen > 0) {
        root->leftChild = fromList(leftLen, args);
    }
    if (rightLen > 0) {
        root->rightChild = fromList(rightLen, args+middle+1);
    }
    return root;
}
//
// int *toList(binTree *root) {
//     if (root == NULL) {
//         return NULL;
//     }
//     int *leftChild; int *rightChild;
//     if (root->leftChild != NULL) {
//         leftChild = toList(root->leftChild);
//     } else {
//         leftChild = NULL;
//     }
//     if (root->rightChild != NULL) {
//         rightChild = toList(root->leftChild);
//     } else {
//         rightChild = NULL;
//     }
//     int selfValue [1] = {root->value};
//     int* total = malloc(sizeof(leftChild) + sizeof(selfValue) + sizeof(rightChild));
//     memcpy(total + length(leftChild) * sizeof(int), selfValue, length(selfValue) * sizeof(int));
//     memcpy(total + 1, rightChild, length(rightChild) * sizeof(int));
//     free(leftChild);
//     free(selfValue);
//     free(rightChild);
//     return leftChild;
// }
    // memcopy
//     if (list == NULL) {
//         return "DUPA hehe";
//     }
//     free(leftChild);
//     free(selfValue);
//     free(rightChild);
//     return list;
// }

int main(int argc, char const *argv[]) {
    int *p;
    int vars[5] = {2, 3, 4, 5, 6};
    p = vars;
    binTree *root = fromList(5, p);
    int *list = toList(root);
    for(int i = 0; i < 3; i++) {
        printf("%d ", *(list+i));
    }
    printf("\n");
    printf ("Tree length: %d\n", length(root));
    printf ("Tree depth: %d\n", depth(root));
    printf ("Tree minimum: %d\n", minimum(root));
    printf ("Tree maximum: %d\n", maximum(root));
    for (int i=0; i < 5; i++) {
        printf ("%d in Tree: %d\n", vars[i], search(root, vars[i]));
    }
    printf ("Root value: %d\n", root->value);
    removeFromTree(root, 4);
    printf ("4 Not in tree: %d\n", search(root, 4));
    printf ("Root value: %d\n", root->value);
    destroyTree(root);
    return 0;
}
