
#ifndef _1180779_SHARED_
#define _1180779_SHARED_

#include <stdlib.h>
#include <stdio.h>

#ifdef _MSC_VER

size_t getline(char** lineptr, size_t* n, FILE* stream);

#endif


#define ERROR(source) fprintf(stderr, "file: %s, line: %d, ", __FILE__, __LINE__), perror(source), exit(EXIT_FAILURE)

#define MALLOC(ptr, s, singlesize)  do { \
                                        ptr = malloc(singlesize * s); \
                                        if(ptr == NULL) \
                                            ERROR("malloc"); \
                                    } while(0)

#define REALLOC(ptr, s, singlesize) do { \
                                        void *temp = realloc(ptr, s * singlesize); \
                                        if(temp == NULL) \
                                            ERROR("realloc"); \
                                        ptr = temp; \
                                    } while(0)

#endif