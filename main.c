#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRINGIFY(x) #x
#define MACRO(x)     STRINGIFY(x)

char *readIn() {
    char *line = NULL;
    size_t size;
    if (getline(&line, &size, stdin) != -1) {
        return line;
    }
    return "";
}

int main(int argc, char const *argv[]) {
    #ifdef DEBUG
    printf("+--------------------+\n| Build ID: %s |\n+--------------------+\n\n", MACRO(BUILDID));
    #endif



    return 0;
}
