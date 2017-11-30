#include<stdio.h>
#include<stdlib.h>

int fibonacci(int);

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: %s and an integer argument \n");
        return 1;
    }

    if(!atoi(argv[1])) {
        printf("Usage: %s should be integer\n", argv[1]);
        return 1;
    }

    for (int i = 0; i<atoi(argv[1]);i++) {
        printf("%d\t", fibonacci(i));
    }

    return EXIT_SUCCESS;
}

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

