#include <stdio.h>
#include <stdlib.h>
#include "shared.h"
#include "vec.h"

VEC_DEFINE_NONAME(long long int)

void scanf_report(vec* v) 
{
    vecClear(v);
    long long int item;
    do  {
        if (scanf(" %lld", &item) != 1)
            ERROR("scanf");
        vecAdd(v, item);
    } while(getchar() != '\n');
}


#define INCREASING 0
#define DECREASING 1
int part1(vec* v) 
{
    int type;
    if (*vecAt(v, 1) - *vecAt(v, 0) > 0)
        type = INCREASING;
    else
        type = DECREASING;

    long long int diff;
    for (int i = 0; i < v->size - 1; ++i) {
        diff = *vecAt(v, i + 1) - *vecAt(v, i);
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
    vecInit(&v);
    vecInit(&temp);

    int n;
    long long int res_part1 = 0,
                  res_part2 = 0;
    if (scanf("%d", &n) != 1)
        ERROR("scanf");
    for (int i = 0; i < n; ++i) {
        scanf_report(&v);
        res_part1 += part1(&v);
    }
    printf("\n\nPart1: Result: %lld\nPart2: Result: %lld\n", res_part1, res_part2);

    vecDestroy(&temp);
    vecDestroy(&v);
    return EXIT_SUCCESS;
}