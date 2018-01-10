#include <stdio.h>
#include <string.h>
#define N 10

int main(int argc, char* argv[argc+1]) {
    size_t const len = strlen(argv[0]);
    char name[len+1];

    memcpy(name, argv[0], len);
    name[len] = 0;
    if (!strcmp(name, argv[0])) {
        printf("program_name_\"%s\"_successfully_copied\n", name);
    }
    else {
        printf("copying_%s_leads_to_different_string_%s\n", argv[0], name);
    }
}

