#include <stdio.h>;

int main (int argc, char* argv[]) {
    int *myArray = (int*) calloc(420, sizeof(int));
    int i;

    for (i = 0; i < 420; i++) {
        myArray[i] = i + 1;
    }

    for (i = 0; i < 420; i++) {
        printf("i: %d, value: %d\n", i, myArray[i]);
    }

    free (myArray);
    return 0;
}
