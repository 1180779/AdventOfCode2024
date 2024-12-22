
#include "par.h"
#include "shared.h"
#include <string.h>

#define isDigit(c) ((c) >= '0' && (c) <= '9')

void parInit(par* p, char* string, int len) 
{
    p->strLen = len;
    MALLOC(p->string, p->strLen + 1, sizeof(char));
    strcpy(p->string, string);
    p->c = -1;
}

int parMatch(par* p, char c) 
{
    if (p->c == p->strLen - 1)
        return 0;
    ++p->c;
    if (p->string[p->c] == c)
        return 1;
    return 0;
}

int parMatchInt(par* p) 
{
    int res = 0;
    char c = p->string[++p->c];
    if (!isDigit(c)) {
        --p->c;
        return -1;
    }
    while (p->c < (int)p->strLen && isDigit(c)) {
        res = res * 10 + c - '0';
        c = p->string[++p->c];
    }
    --p->c;
    return res;
}

parRes parMatchPattern(par* p) 
{
    parRes res = { 0 };

    while (p->c < (int)p->strLen - 1) {
        if (!parMatch(p, 'm'))
            continue;
        if (!parMatch(p, 'u'))
            continue;
        if (!parMatch(p, 'l'))
            continue;
        if (!parMatch(p, '('))
            continue;

        res.i1 = parMatchInt(p);
        if (res.i1 == -1)
            continue;

        if (!parMatch(p, ','))
            continue;

        res.i2 = parMatchInt(p);
        if (res.i2 == -1)
            continue;

        if (!parMatch(p, ')'))
            continue;
        break;
    }
    return res;
}

void parDestroy(par* p) 
{
    free(p->string);
}