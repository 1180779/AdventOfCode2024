#include <stdlib.h>
#include <stdio.h>
#include "vec.h"

#define VEC_PRINT(v) VEC_PRINT_SIMPLE(5d)

VEC_DEFINE_NONAME(int)

int main() {
    vec v;
    vec_init(&v);

    // add
    for (int i = 0; i < 15; ++i) {
        vec_add(&v, i);
    }
    VEC_PRINT(v);

    // add to front
    for (int i = 0; i < 5; ++i) {
        vec_addf(&v, i - 99);
        VEC_PRINT(v);
    }
    VEC_PRINT(v);

    // remove
    for (int i = 0; i < 3; ++i) {
        vec_removel(&v);
    }
    VEC_PRINT(v);

    // remove from front
    for (int i = 0; i < 3; ++i) {
        vec_removef(&v);
    }
    VEC_PRINT(v);

    // clear
    vec_clear(&v);
    VEC_PRINT(v);

    vec_destroy(&v);
}