#include "pointer.h"

Pointer dataToPointer(DataType type, ...)
{
    va_list args;
    va_start(args, type);

    void* ptr = NULL;

    switch (type) 
    {
        case TYPE_INT: 
        {
            int* p = (int*)malloc(sizeof(int));
            if (!p) return NULL;
            *p = va_arg(args, int);
            ptr = p;
            break;
        }
        case TYPE_FLOAT: 
        {
            float* p = (float*)malloc(sizeof(float));
            if (!p) return NULL;
            *p = (float)va_arg(args, double); // float é promovido para double em varargs
            ptr = p;
            break;
        }
        case TYPE_DOUBLE: 
        {
            double* p = (double*)malloc(sizeof(double));
            if (!p) return NULL;
            *p = va_arg(args, double);
            ptr = p;
            break;
        }
        case TYPE_CHAR:
        {
            char* p = (char*)malloc(sizeof(char));
            if (!p) return NULL;
            *p = (char)va_arg(args, int); // char é promovido para int em varargs
            ptr = p;
            break;
        }
        case TYPE_STRING: 
        {
            const String str = va_arg(args, const String);
            ptr = strdup(str); // Aloca e copia a string
            if (!ptr) return NULL;
            break;
        }
    }

    va_end(args);
    return ptr;
}

void freePointer(Pointer data)
{
    if (data != NULL)
    {
        free(data); // Libera a memória ocupada pelos dados
    }
}

int compareData(Pointer data1, Pointer data2, DataType type)
{
    switch (type)
    {
    case TYPE_INT:
        return *(int*)data1 - *(int*)data2;
    case TYPE_FLOAT:
        return *(float*)data1 - *(float*)data2;
    case TYPE_DOUBLE:
        return *(double*)data1 - *(double*)data2;
    case TYPE_CHAR:
        return *(char*)data1 - *(char*)data2;
    case TYPE_STRING:
        return strcmp((String)data1, (String)data2);
    default:
        break;
    }
}