#include <stdlib.h>
#include <stdio.h>
#include "vec.h"

#define VEC_PRINT(v) VEC_PRINT_SIMPLE(5d)

VEC_DEFINE_NONAME(int)

int main() {
    vec v = VECINIT;

    // add
    for (int i = 0; i < 15; ++i) {
        vecAdd(&v, i);
    }
    VEC_PRINT(v);

    // add to front
    for (int i = 0; i < 5; ++i) {
        vecAddf(&v, i - 99);
        VEC_PRINT(v);
    }
    VEC_PRINT(v);

    // remove
    for (int i = 0; i < 3; ++i) {
        vecRemovel(&v);
    }
    VEC_PRINT(v);

    // remove from front
    for (int i = 0; i < 3; ++i) {
        vecRemovef(&v);
    }
    VEC_PRINT(v);

    // clear
    vecClear(&v);
    VEC_PRINT(v);

    vecDestroy(&v);
}