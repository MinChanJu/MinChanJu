// Implemented as a linked list

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// Declare Structures of tree
typedef struct node *treePointer;
typedef struct node {
    int data;
    treePointer leftChild, rightChild;
    short int leftThread, rightThread;
} node;

// Declaring dummy and first
treePointer dummy;
treePointer first = NULL;

// Declare the prototype of a function
treePointer search(treePointer ptr,int value); // For convenience, creating a function that finds the same node as a value.
void insert_Root(); // If tree is empty insert the node as root. If root exist give error.
void insert_Left(); // Inserts a left child of the parent.
void insert_Right(); // Inserts a right child of the parent.
treePointer inorder_Succ(treePointer ptr); // Finds the inorder successor of node X.
void inorder_Trav(treePointer ptr); // Find the inorder traversal of the tree.
void freeTree(treePointer ptr); // Free the dynamically allocated memory

int main() {
    // Dummy initialization
    dummy = (treePointer)malloc(sizeof(node));
    dummy->data = 0;

    while (TRUE) {
        int select;
        printf("Binary tree functions: Select the function you like to proceed with,\n");
        printf("    1. Insert root\n");
        printf("    2. Insert left\n");
        printf("    3. Insert right\n");
        printf("    4. Inorder Successor\n");
        printf("    5. Inorder Traversal\n");
        printf("    6. Terminate Program\n");
        printf("Selection choice: ");
        scanf("%d", &select);

        if (select == 6) break;
        else if (select == 1) insert_Root();
        else if (select == 2) insert_Left();
        else if (select == 3) insert_Right();
        else if (select == 4) {
            int X;
            printf("Enter the node which you want to find the successor: ");
            scanf("%d", &X);

            treePointer temp = search(first,X);
            if (temp != NULL) {
                treePointer succ = inorder_Succ(temp);

                if (succ == dummy) printf("The inorder succesor of %d is not exist\n", X);
                else printf("The inorder successor of %d is %d\n", X, succ->data);
            } else printf("Error: Not found you entered.\n");
        }
        else if (select == 5) inorder_Trav(first);
        else printf("You entered the wrong number.\n");
    }

    printf("Terminate the Program\n");
    freeTree(first);
    free(dummy);
    
    return 0;
}

// If tree is empty insert the node as root. If root exist give error.
void insert_Root() {
    if (first == NULL) {
        int root;
        printf("Enter the root node information: ");
        scanf("%d", &root);

        first = (treePointer)malloc(sizeof(node));
        first->data = root;
        first->leftChild = dummy;
        first->rightChild = dummy;
        first->leftThread = TRUE;
        first->rightThread = TRUE;

        printf("The root node is %d.\n", root);

        return;
    } else printf("Error: This is not an empty binary tree.\n");
}

// Inserts a left child of the parent.
void insert_Left() {
    int parent;
    printf("Enter the parent information: ");
    scanf("%d", &parent);

    treePointer s = search(first, parent);
    if (s == NULL) {
        printf("Error: Not found parent\n");
        return;
    }

    treePointer temp;
    int left_child;
    printf("Enter the left child information: ");
    scanf("%d", &left_child);

    treePointer l = (treePointer)malloc(sizeof(node));
    l->data = left_child;
    l->leftChild = s->leftChild;
    l->leftThread = s->leftThread;
    l->rightChild = s;
    l->rightThread = TRUE;

    s->leftChild = l;
    s->leftThread = FALSE;
    if (l->leftThread == FALSE){
        temp = inorder_Succ(l);
        temp->rightChild = l;
    }

    printf("The left child is %d\n", left_child);
}

// Inserts a right child of the parent.
void insert_Right() {
    int parent;
    printf("Enter the parent information: ");
    scanf("%d", &parent);

    treePointer s = search(first, parent);
    if (s == NULL) {
        printf("Error: Not found parent\n");
        return;
    }

    treePointer temp;
    int right_child;
    printf("Enter the right child information: ");
    scanf("%d", &right_child);

    treePointer r = (treePointer)malloc(sizeof(node));
    r->data = right_child;
    r->leftChild = s; 
    r->leftThread = TRUE;
    r->rightChild = s->rightChild;
    r->rightThread = s->rightThread;

    s->rightChild = r; 
    s->rightThread = FALSE;
    if (r->rightThread == FALSE){
        temp = inorder_Succ(r);
        temp->leftChild = r;
    }

    printf("The right child is %d\n", right_child);
}

// Finds the inorder successor of node X.
treePointer inorder_Succ(treePointer X) {
    treePointer temp;
    temp = X->rightChild;
    if (!X->rightThread){
        while (!temp->leftThread) temp = temp->leftChild;
    }

    return temp;
}

// Find the inorder traversal of the tree.
void inorder_Trav(treePointer ptr) {
    if (ptr == first) printf("The inorder traversal of the tree is ");

    if (ptr->leftThread == FALSE) inorder_Trav(ptr->leftChild);
    printf("%d ", ptr->data);
    if (ptr->rightThread == FALSE) inorder_Trav(ptr->rightChild); 

    if(ptr == first) printf("\n");
}

// For convenience, creating a function that finds the same node as a value.
treePointer search(treePointer ptr,int value) {
    if (ptr) {
        if (ptr->data == value) return ptr;

        if (ptr->leftThread == FALSE) {
            treePointer temp = search(ptr->leftChild, value);
            if (temp != NULL) return temp;
        }

        if (ptr->rightThread == FALSE) {
            treePointer temp = search(ptr->rightChild, value);
            if (temp != NULL) return temp;
        }
    }

    return NULL;
}

// Free the dynamically allocated memory
void freeTree(treePointer ptr) {
    if (ptr == NULL) return;

    if (ptr->leftThread == FALSE) {
        freeTree(ptr->leftChild);
    }

    if (ptr->rightThread == FALSE) {
        freeTree(ptr->rightChild);
    }

    free(ptr);
}