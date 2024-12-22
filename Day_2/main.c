#include <stdio.h>
#include <stdlib.h>
#include "shared.h"
#include "vec.h"

typedef long long int;

typedef struct vec {
    long long int* data; 
    _vec_size reserved; 
    _vec_size size;
} vec; 

void vec_init(vec* v) 
{
    do {
        v->data = malloc(sizeof(long long int) * 8); 
        if (v->data == ((void*)0)) 
            fprintf((__acrt_iob_func(2)), "file: %s, line: %d, ", "C:\\Users\\rdkgs\\MojePliki\\coding\\AdventOfCode2024\\Day_2\\main.c", __LINE__), perror("malloc"), exit(1);
    } while (0); 
    v->reserved = 8; 
    v->size = 0;
} 

void vec_destroy(vec* v) 
{
    free(v->data); 
    v->reserved = 0; 
    v->size = 0;
} 

inline void vec_reserve(vec* v, _vec_size s) 
{
    if (s <= v->reserved) 
        return; 
    do {
        void* temp = realloc(v->data, s * sizeof(long long int)); 
        if (temp == ((void*)0)) 
            fprintf((__acrt_iob_func(2)), "file: %s, line: %d, ", "C:\\Users\\rdkgs\\MojePliki\\coding\\AdventOfCode2024\\Day_2\\main.c", __LINE__), perror("realloc"), exit(1);
        v->data = temp;
    } while (0); 
    v->reserved = s;
} 

inline void vec_resize(vec* v, _vec_size s) 
{
    do {
        void* temp = realloc(v->data, s * sizeof(long long int)); 
        if (temp == ((void*)0)) 
            fprintf((__acrt_iob_func(2)), "file: %s, line: %d, ", "C:\\Users\\rdkgs\\MojePliki\\coding\\AdventOfCode2024\\Day_2\\main.c", __LINE__), perror("realloc"), exit(1);
        v->data = temp;
    } while (0); 
    v->reserved = s; 
    v->size = s;
} 

inline void vec_clear(vec* v) 
{
    v->size = 0;
} 

inline long long int* vec_at(vec* v, _vec_size i) 
{
    if (v->size < i) 
        fprintf((__acrt_iob_func(2)), "file: %s, line: %d, ", "C:\\Users\\rdkgs\\MojePliki\\coding\\AdventOfCode2024\\Day_2\\main.c", __LINE__), perror("Index out of range"), exit(1);
    return &v->data[i];
} 

void vec_add(vec* v, long long int i) 
{
    if (v->reserved == v->size) 
        vec_reserve(v, v->size * 2); 
    v->data[v->size++] = i;
} 

void vec_addf(vec* v, long long int i) 
{
    if (v->reserved == v->size) 
        vec_reserve(v, v->size * 2); 
    memmove(v->data + 1, v->data, v->size * sizeof(long long int)); 
    v->data[0] = i; 
    ++v->size;
} 

void vec_removef(vec* v) 
{
    if (v->size == 0) 
        return; 
    --v->size; 
    memmove(v->data, v->data + 1, v->size * sizeof(long long int));
} 

void vec_removel(vec* v) {
    if (v->size == 0) 
        return; 
    --v->size;
}

void scanf_report(vec* v) 
{
    vec_clear(v);
    long long int item;
    do  {
        if (scanf(" %lld", &item) != 1)
            ERROR("scanf");
        vec_add(v, item);
    } while(getchar() != '\n');
}


#define INCREASING 0
#define DECREASING 1
int part1(vec* v) 
{
    int type;
    if (*vec_at(v, 1) - *vec_at(v, 0) > 0)
        type = INCREASING;
    else
        type = DECREASING;

    long long int diff;
    for (int i = 0; i < v->size - 1; ++i) {
        diff = *vec_at(v, i + 1) - *vec_at(v, i);
        if (type == INCREASING && diff < 1) {
            return 0;
        }
        else if (type == DECREASING && diff > -1) {
            return 0;
        }
        else if (llabs(diff) > 3)
            return 0;
    }
    return 1;
}

int main() {
    vec v, temp;
    vec_init(&v);
    vec_init(&temp);

    int n;
    long long int res_part1 = 0,
                  res_part2 = 0;
    if (scanf("%d", &n) != 1)
        ERROR("scanf");
    for (int i = 0; i < n; ++i) {
        scanf_report(&v);
        //VEC_PRINT_SIMPLE(10lld);
        res_part1 += part1(&v);
    }
    printf("\n\nPart1: Result: %lld\nPart2: Result: %lld\n", res_part1, res_part2);

    vec_destroy(&temp);
    vec_destroy(&v);
    return EXIT_SUCCESS;
}