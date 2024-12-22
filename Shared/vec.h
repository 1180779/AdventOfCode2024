
#ifndef _1180779_VEC_
#define _1180779_VEC_

#ifdef _MSC_VER
#pragma warning ( disable: 6305 )
#endif

#include "shared.h"
#include <string.h>

typedef unsigned long long int _vec_size;

// vec data at index i
#define vec_dat(v, i)           v.data[i]

#define VEC_INIT_SIZE 8
#define VEC_SCALING_FACTOR 2
#define _vec_at(v, i)           v->data[i]

#define VEC_DEFINE_EXT(type, tname) \
                                typedef struct vec##tname { \
                                    type* data; \
                                    _vec_size reserved; \
                                    _vec_size size; \
                                } vec##tname; \
                                \
                                \
                                \
                                void vec##tname##_init(vec##tname* v) \
                                { \
                                    MALLOC(v->data, VEC_INIT_SIZE, sizeof(type)); \
                                    v->reserved = VEC_INIT_SIZE; \
                                    v->size = 0; \
                                } \
                                \
                                void vec##tname##_destroy(vec##tname* v) \
                                { \
                                    free(v->data); \
                                    v->reserved = 0; \
                                    v->size = 0; \
                                } \
                                \
                                inline void vec##tname##_reserve(vec##tname* v, _vec_size s) \
                                { \
                                    if(s <= v->reserved) \
                                        return; \
                                    REALLOC(v->data, s, sizeof(type)); \
                                    v->reserved = s; \
                                } \
                                \
                                inline void vec##tname##_resize(vec##tname* v, _vec_size s) \
                                { \
                                    REALLOC(v->data, s, sizeof(type)); \
                                    v->reserved = s; \
                                    v->size = s; \
                                } \
                                \
                                inline void vec##tname##_clear(vec##tname* v) \
                                {\
                                    v->size = 0; \
                                }\
                                \
                                \
                                \
                                inline type* vec##tname##_at(vec##tname* v, _vec_size i) \
                                { \
                                    if(v->size < i) \
                                        ERROR("Index out of range"); \
                                    return &_vec_at(v, i); \
                                } \
                                \
                                \
                                \
                                void vec##tname##_add(vec##tname* v, type i) \
                                { \
                                    if(v->reserved == v->size) \
                                        vec##tname##_reserve(v, v->size * VEC_SCALING_FACTOR); \
                                    v->data[v->size++] = i; \
                                } \
                                \
                                void vec##tname##_addf(vec##tname* v, type i) \
                                { \
                                    if(v->reserved == v->size) \
                                        vec##tname##_reserve(v, v->size * VEC_SCALING_FACTOR); \
                                    memmove(v->data + 1, v->data, v->size * sizeof(type)); \
                                    _vec_at(v, 0) = i; \
                                    ++v->size; \
                                } \
                                \
                                \
                                \
                                void vec##tname##_removef(vec##tname* v) \
                                { \
                                    if(v->size == 0) \
                                        return; \
                                    --v->size; \
                                    memmove(v->data, v->data + 1, v->size * sizeof(type)); \
                                } \
                                \
                                void vec##tname##_removel(vec##tname* v) \
                                { \
                                    if(v->size == 0) \
                                        return; \
                                    --v->size;\
                                }
                                
#define _VEC_DEFINE_EXT(type, tname) VEC_DEFINE_EXT(type, tname)

#define VEC_DEFINE_NONAME(type) _VEC_DEFINE_EXT(type, )
#define VEC_DEFINE(type) VEC_DEFINE_EXT(type, type)


// related macros
#define VEC_PRINT_SIMPLE(format) \
                                do { \
                                    printf("["); \
                                    for (int i = 0; i < (v).size; ++i) { \
                                        printf("%" #format, *vec_at(&(v), i)); \
                                    } \
                                    printf("]\n"); \
                                } while(0)


#endif