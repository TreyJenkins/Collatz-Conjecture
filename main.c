#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRINGIFY(x) #x
#define MACRO(x)     STRINGIFY(x)


int ntoo(int n) {
    int i = 0;

    while (n > 1) {
        printf("%i -> ", n);
        if ((n % 2) == 0) {
            n = n / 2;
        } else {
            n = (3 * n) + 1;
        }
        printf("%i\n", n);
        i++;
    }

    printf("Took %i steps to reach 1\n", i);
    return i;
}

int ntod(int m, int max) {
    int i, n;

    n = m;

    if (max < n) {
        printf("!! Max < n !!\n");
        exit(0);
    }

    int res[2];

    for (uintmax_t v = n; v <= max; v++) {
        i = 0;
        int c = v;
        while (c > 1) {
            //printf("%i -> ", (int) c);
            if ((c % 2) == 0) {
                c = c / 2;
            } else {
                c = (3 * c) + 1;
            }
            //printf("%i, ", (int) c);
            i++;
        }
        printf("Took %i steps for %i to reach 1, %.2f complete\n", i, (int) v, ((float) v/ (float)max)*100);
        if (i > res[1]) {
            res[0] = (int) v;
            res[1] = i;
        }
    }
    printf("The longest chain was produced by %i, with %i steps\n", res[0], res[1]);
    return res[0];
}

int main(int argc, char const *argv[]) {
    #ifdef DEBUG
    printf("+--------------------+\n| Build ID: %s |\n+--------------------+\n\n", MACRO(BUILDID));
    #endif

    if (argc < 2) {
        printf("Provide starting number as an argument\n");
        exit(0);
    }

    int n = atoi(argv[1]);


    if (argc > 2) {
        ntod(n, atoi(argv[2]));
    } else {
        ntoo(n);
    }

    return 0;
}
