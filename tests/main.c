#include <stdlib.h>
#include <stdio.h>
#include "vec.h"

VEC_DEFINE(int)

int main() {
    vec_int v;
    vec_int_init(&v);

    for (int i = 0; i < 15; ++i) {
        vec_int_add(&v, i);
    }

    for (int i = 0; i < v.size; ++i) {
        printf("%10d", vec_int_at(&v, i));
    }
}