#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int id;
    char directory[40];
    struct tree *rigth;
    struct tree *left;
} Tree;