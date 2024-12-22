
#ifndef _1180779_PARSER_
#define _1180779_PARSER_

typedef struct parRes {
    int i1;
    int i2;
} parRes;

typedef struct par {
    char* string;
    size_t strLen;
    int c; // string char index
    short enabled;
} par;

void parInit(par* p, char* string, int len);
int parMatch(par* p, char c);
int parMatchInt(par* p);
parRes parMatchPattern(par* p);
parRes parMatchPattern2(par* p);
void parDestroy(par* p);

#endif
