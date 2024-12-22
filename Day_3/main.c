#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "par.h"
#include "shared.h"
#include "vec.h"

VEC_DEFINE_NONAME(char)

vec read() 
{
    vec v;
    vecInit(&v);
    char c;
    while ((c = getchar()) != '\n') {
        vecAdd(&v, c);
    }
    vecAdd(&v, '\0');
    return v;
}

void part1(vec *v) 
{
    par p = { 0 };
    parInit(&p, v->data, v->size);

    int res = 0;
    while (p.c < (int)p.strLen - 1) {
        parRes i = parMatchPattern(&p);
        if (i.i1 != -1 && i.i2 != -1) {
            res += i.i1 * i.i2;
        }
    }

    printf("Part1: Result: %d\n", res);
    parDestroy(&p);
}

int main() 
{
    vec v = read();
    part1(&v);
    vecDestroy(&v);
    return EXIT_SUCCESS;
}