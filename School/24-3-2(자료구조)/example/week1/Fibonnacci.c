#include <stdio.h>

int fib(int n);

int main() {
    int a;
    for (int i = 0; i < 10; i++) {
        printf("%d : %d\n", i, fib(i));
    }
    
    return 0;
}

int fib(int n) {
    if (n <= 1) return n;
    else return fib(n-1)+fib(n-2);
}