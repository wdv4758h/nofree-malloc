#include <stdio.h>
#include <stdlib.h>

int main() {

    getchar();

    while (1) {
        char* x = malloc(sizeof(char));
        *x = 'a';
        printf("char address : %p\n", x);
        getchar();
    }

    return 0;
}
