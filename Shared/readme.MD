# Shared code

## shared.h

### functions

- ```getline``` function declaration
```c
size_t getline(char** lineptr, size_t* n, FILE* stream);
```

### macros
- ```ERROR``` macro - handling of program breaking errors
```c
#define ERROR(source) fprintf(stderr, "file: %s, line: %d, ", __FILE__, __LINE__), perror(source), exit(EXIT_FAILURE)
```


- ```MALLOC``` macro - handling of program breaking malloc error
```c
#define MALLOC(ptr, s, singlesize)  do { \
                                        ptr = malloc(singlesize * s); \
                                        if(ptr == NULL) \
                                            ERROR("malloc"); \
                                    } while(0)
```

- ```REALLOC``` macro - handing of program breaking realloc error
```c
#define REALLOC(ptr, s, singlesize) do { \
                                        void *temp = realloc(ptr, s * singlesize); \
                                        if(temp == NULL) \
                                            ERROR("realloc"); \
                                        ptr = temp; \
                                    } while(0)
```

## vec.h
Provides a simple type parameterized dynamic array struct ```vec```. 

### Before first use
Use one of the following macros to define the class and functions
- ```VEC_DEFINE_EXT(type, tname)``` - define a ```vec##tname``` class using type ```type``` 
as item type
- ```VEC_DEFINE_NONAME(type)``` - define a ```vec``` class using type ```type``` 
as item type
- ```VEC_DEFINE(type)``` - define a ```vec##type``` class using type ```type``` 
as item type. Equivalent to ```VEC_DEFINE_EXT(type, type)```

