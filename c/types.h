typedef struct linkedList {
    int value;
    struct linkedList* prev;
    struct linkedList* next;
} linkedList;

linkedList *getLinkedList();
linkedList *copyList(linkedList *root);
void destroyList(linkedList *root);
void addToListRec(linkedList *root, int value);
linkedList *joinLists(linkedList *first, linkedList *last);
linkedList *addValueToList(linkedList* root, int value);
void addToListLoop(linkedList *root, int argc, int *argv);
void removeFromList(linkedList *root, int value);
int listLength(linkedList *root);
void printList(linkedList *root);

typedef struct binTree {
    int value;
    struct binTree* leftChild;
    struct binTree* rightChild;
} binTree;

binTree *getTree ();
void destroyTree(binTree *root);
void insert(binTree *root, int value);
void insertMany(binTree *root, int argsc, int *args);
int search(binTree *root, int value);
int length(binTree *root);
int depth(binTree *root);
int minimum(binTree *root);
int maximum(binTree *root);
void removeFromTree(binTree *root, int value);
binTree *fromList(int len, int *args);
linkedList *toList(binTree *root);
