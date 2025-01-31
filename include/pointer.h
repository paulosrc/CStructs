#ifndef POINTER_H
#define POINTER_H

#include <assert.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>

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

Pointer DataToPointer(DataType type, ...);

#endif