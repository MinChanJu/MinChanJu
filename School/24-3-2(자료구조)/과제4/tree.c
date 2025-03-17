// Implemented as a array
// Because it's complete Binary Tree or full Binary Tree

#include <stdio.h>
#include <stdlib.h>

// Declare the prototype of a function
void insert_Root(int** Binary_Tree, int* node); // If tree is empty insert the node as root. If root exist give error.
void insert_Left(int** Binary_Tree, int* node, int* size); // Inserts a left child of the parent.
void insert_Right(int** Binary_Tree, int* node, int* size); // Inserts a right child of the parent.
void inorder_Succ(int* Binary_Tree, int node); // Finds the inorder successor of node X.
void inorder_Trav(int* Binary_Tree, int node, int i); // Find the inorder traversal of the tree.

int main() {
    // node : Number of node
    // size : size of array
    int node = 0, size = 2;
    int* Binary_Tree = (int*)malloc(size*sizeof(int));

    if (Binary_Tree == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    while (1) {
        int select;
        printf("Binary tree functions: Select the function you like to proceed with,\n");
        printf("\t1. Insert root\n");
        printf("\t2. Insert left\n");
        printf("\t3. Insert right\n");
        printf("\t4. Inorder Successor\n");
        printf("\t5. Inorder Traversal\n");
        printf("\t6. Terminate Program\n");
        printf("Selection choice: ");
        scanf("%d", &select);

        if (select == 6) break;
        else if (select == 1) insert_Root(&Binary_Tree, &node);
        else if (select == 2) insert_Left(&Binary_Tree, &node, &size);
        else if (select == 3) insert_Right(&Binary_Tree, &node, &size);
        else if (select == 4) inorder_Succ(Binary_Tree, node);
        else if (select == 5) inorder_Trav(Binary_Tree, node, 1);
        else printf("You entered the wrong number.\n");
    }

    printf("Terminate the Program\n");
    free(Binary_Tree);
    
    return 0;
}

// If tree is empty insert the node as root. If root exist give error.
void insert_Root(int** Binary_Tree, int* node) {
    if (*node != 0) {
        printf("Error: This is not an empty binary tree.\n");
        return;
    }

    int root;
    printf("Enter the root node information: ");
    scanf("%d", &root);

    (*Binary_Tree)[1] = root;

    printf("The root node is %d.\n", root);
    (*node)++;

    return;
}

// Inserts a left child of the parent.
void insert_Left(int** Binary_Tree, int* node, int* size) {
    int parent;
    printf("Enter the parent information: ");
    scanf("%d", &parent);

    for (int i = 1; i <= *node; i++) {
        if ((*Binary_Tree)[i] == parent) {
            if (2*i <= *node) {
                printf("The left child of %d already exists\n", parent);
                return;
            }

            int left_child;
            printf("Enter the left child information: ");
            scanf("%d", &left_child);

            if (2*i >= (*size)) {
                int* temp = (int*)realloc(*Binary_Tree, ((*size)*2) * sizeof(int));

                if (temp == NULL) {
                    printf("Memory allocation failed.\n");
                    return;
                }
                
                *size *= 2;
                *Binary_Tree = temp;
            }

            (*Binary_Tree)[2*i] = left_child;

            printf("The left child is %d\n", left_child);
            (*node)++;

            return;
        }
    }

    printf("Error: Not found parent\n");

    return;
}

// Inserts a right child of the parent.
void insert_Right(int** Binary_Tree, int* node, int* size) {
    int parent;
    printf("Enter the parent information: ");
    scanf("%d", &parent);

    for (int i = 1; i <= *node; i++) {
        if ((*Binary_Tree)[i] == parent) {
            if (2*i+1 <= *node) {
                printf("The right child of %d already exists\n", parent);
                return;
            }

            int right_child;
            printf("Enter the right child information: ");
            scanf("%d", &right_child);

            if (2*i+1 >= (*size)) {
                int* temp = (int*)realloc(*Binary_Tree, ((*size)*2) * sizeof(int));

                if (temp == NULL) {
                    printf("Memory allocation failed.\n");
                    return;
                }

                *size *= 2;
                *Binary_Tree = temp;
            }

            (*Binary_Tree)[2*i+1] = right_child;

            printf("The right child is %d\n", right_child);
            (*node)++;

            return;
        }
    }

    printf("Error: Not found parent\n");

    return;
}

// Finds the inorder successor of node X.
void inorder_Succ(int* Binary_Tree, int node) {
    int X;
    printf("Enter the node which you want to find the successor: ");
    scanf("%d", &X);

    for (int i = 1; i <= node; i++) {
        if (Binary_Tree[i] == X) {
            int temp;

            if (2*i+1 <= node) {
                temp = 2*i+1;
                while (temp*2 <= node) temp *= 2;
            } else {
                temp = i;
                while (temp >= 1 && temp == 2*(temp/2)+1) temp /= 2;
                temp /= 2;
            }
            
            if (temp > node || temp < 1) printf("The inorder succesor of %d is not exist\n", X);
            else printf("The inorder successor of %d is %d\n", X, Binary_Tree[temp]);

            return;
        }
    }

    printf("Error: Not found you entered.\n");
    
    return;
}

// Find the inorder traversal of the tree.
void inorder_Trav(int* Binary_Tree, int node, int i) {
    if (i == 1) printf("The inorder traversal of the tree is ");

    if (i <= node) {
        inorder_Trav(Binary_Tree, node, 2*i);
        printf("%d ", Binary_Tree[i]);
        inorder_Trav(Binary_Tree, node, 2*i+1);
    }

    if (i == 1) printf("\n");

    return;
}