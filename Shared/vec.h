
#ifndef _1180779_VEC_
#define _1180779_VEC_

#ifdef _MSC_VER
#pragma warning ( disable: 6305 )
#endif

#include "shared.h"
#include <string.h>

typedef unsigned long long int _vec_size;

#define VEC_INIT_SIZE 8
#define VEC_SCALING_FACTOR 2

#define vec_at(v, i)            v->data[i]

#define VEC_DEFINE_EXT(type, tname) \
                                typedef struct vec_##tname { \
                                    type* data; \
                                    _vec_size reserved; \
                                    _vec_size size; \
                                } vec_##tname; \
                                \
                                \
                                \
                                void vec_##tname##_init(vec_##tname* v) \
                                { \
                                    MALLOC(v->data, VEC_INIT_SIZE, sizeof(type)); \
                                    v->reserved = VEC_INIT_SIZE; \
                                    v->size = 0; \
                                } \
                                \
                                void vec_##tname##_destroy(vec_##tname* v, _vec_size s) \
                                { \
                                    free(v->data); \
                                    v->reserved = 0; \
                                    v->size = 0; \
                                } \
                                \
                                inline void vec_##tname##_reserve(vec_##tname* v, _vec_size s) \
                                { \
                                    if(s < v->reserved) \
                                        return; \
                                    REALLOC(v->data, s, sizeof(type)); \
                                    v->reserved = s; \
                                } \
                                \
                                inline void vec_##tname##_resize(vec_##tname* v, _vec_size s) \
                                { \
                                    REALLOC(v->data, s, sizeof(type)); \
                                    v->reserved = s; \
                                    v->size = s; \
                                } \
                                \
                                \
                                \
                                inline type vec_##tname##_at(vec_##tname* v, _vec_size i) \
                                { \
                                    return vec_at(v, i); \
                                } \
                                \
                                \
                                \
                                void vec_##tname##_add(vec_##tname* v, type i) \
                                { \
                                    if(v->reserved == v->size) \
                                        vec_##tname##_reserve(v, v->size * VEC_SCALING_FACTOR); \
                                    v->data[v->size++] = i; \
                                } \
                                \
                                void vec_##tname##_addf(vec_##tname* v, type i) \
                                { \
                                    if(v->reserved == v->size) \
                                        vec_##tname##_reserve(v, v->size * VEC_SCALING_FACTOR); \
                                    memcpy(v->data + sizeof(type), v->data, v->size); \
                                    vec_at(v, 0) = i; \
                                } \
                                \
                                \
                                \
                                void vec_##tname##_removef(vec_##tname* v) \
                                { \
                                    if(v->size == 0) \
                                        return; \
                                    --v->size; \
                                    memcpy(v->data, v->data + sizeof(type), v->size); \
                                } \
                                \
                                void vec_##tname##_removel(vec_##tname* v) \
                                { \
                                    if(v->size == 0) \
                                        return; \
                                    --v->size;\
                                }
                                

#define VEC_DEFINE(type) VEC_DEFINE_EXT(type, type)

#endif