#ifndef POINTER_H
#define POINTER_H

#include <assert.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>

typedef char* String;  // Alias para string
typedef void* Pointer; // Alias para ponteiro genérico

// Enum para definir os tipos suportados
typedef enum
{
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_CHAR,
    TYPE_STRING
} DataType;

Pointer dataToPointer(DataType type, ...);
void freePointer(Pointer data);

int pointerToInt(Pointer data);
float pointerToFloat(Pointer data);
double pointerToDouble(Pointer data);
char pointerToChar(Pointer data);
String pointerToString(Pointer data);

int compareData(Pointer data1, Pointer data2, DataType type);

#endif