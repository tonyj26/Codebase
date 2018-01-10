#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    struct animalStruct {
        const char* jay;
        const char* magpie;
        const char* raven;
        const char* chough;
    };

    struct animalStruct const animal = {
        .chough = "chough",
        .raven = "raven",
        .magpie = "magpie",
        .jay = "jay",
    };

    printf(animal.chough);

    return EXIT_SUCCESS;
}

