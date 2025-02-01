#include "pointer.h"

Pointer DataToPointer(DataType type, ...)
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
            const char* str = va_arg(args, const char*);
            ptr = strdup(str); // Aloca e copia a string
            if (!ptr) return NULL;
            break;
        }
    }

    va_end(args);
    return ptr;
}

void FreePointer(Pointer data)
{
    if (data != NULL)
    {
        free(data); // Libera a memória ocupada pelos dados
    }
}
