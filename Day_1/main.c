#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 100000

#define ERROR(source) fprintf(stderr, "file: %s, line: %d, ", __FILE__, __LINE__), perror(source), exit(-1)

#define MALLOC(ptr, s, singlesize)  do { \
                                        ptr = malloc(singlesize * s); \
                                        if(ptr == NULL) \
                                            ERROR("malloc"); \
                                    } while(0)

#define LISTS_INIT(l, s)            do { \
                                        MALLOC(l.data1, s, sizeof(long long int)); \
                                        MALLOC(l.data2, s, sizeof(long long int)); \
                                        l.size = s; \
                                    } while(0); 

#define LISTS_DESTROY(l)            do { \
                                        free(l.data1); \
                                        free(l.data2); \
                                    } while(0)

#define LISTS_PRINT(l)              do { \
                                        for(int i = 0; i < l.size; ++i) { \
                                            printf("%lld %lld\n", l.data1[i], l.data2[i]); \
                                        } \
                                    } while(0)

typedef struct lists {
    long long int* data1;
    long long int* data2;
    int size;
} lists;

int compare(const void* i1, const void* i2) {
    return *(long long int*)i1 - *(long long int*)i2;
}

lists read_data() {
    lists d;

    if (scanf("%d", &d.size) != 1)
        ERROR("scanf");
    LISTS_INIT(d, d.size);

    long long int v1, v2;
    for (int i = 0; i < d.size; ++i) {
        if (scanf(" %lld %lld", &v1, &v2) != 2)
            ERROR("scanf");
        d.data1[i] = v1;
        d.data2[i] = v2;
    }
    return d;
}

void part1(lists d) {
    long long int res = 0;
    for (int i = 0; i < d.size; ++i) {
        res += llabs(d.data2[i] - d.data1[i]);
    }
    
    printf("Part1: Result: %lld\n", res);
}

void part2(lists d) {
    int i2 = 0;
    long long int* temp;
    MALLOC(temp, d.size, sizeof(long long int));
    memset(temp, 0, d.size * sizeof(long long int));
    for(int i1 = 0; i1 < d.size; ++i1) {
        while (d.data2[i2] < d.data1[i1])
            ++i2;
        while (d.data2[i2] == d.data1[i1]) {
            ++temp[i1];
            ++i2;
        }
        if (i1 > 0 && d.data1[i1] == d.data1[i1 - 1])
            temp[i1] = temp[i1 - 1];
    }
    
    long long int res = 0;
    for (int i = 0; i < d.size; ++i) {
        res += temp[i] * d.data1[i];
    }

    free(temp);
    printf("Part2: Result: %lld\n", res);
}

int main() {
    lists d = read_data();
    qsort(d.data1, d.size, sizeof(long long int), compare);
    qsort(d.data2, d.size, sizeof(long long int), compare);

    part1(d);
    part2(d);
}