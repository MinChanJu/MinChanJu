#include <stdio.h>
#include <stdlib.h>

typedef struct Test {
    int key;
} Test;

int main() {
    int size = 3;
    Test *test = (Test*)malloc(size*sizeof(Test));
    test[0].key = 65;
    test[1].key = 10;
    test[2].key = 25;
    for (int i = 0; i < size; i++) {
        printf("%d\n", test[i].key);
    }
    printf("\n%d\n", (test+1)->key);
}