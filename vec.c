//
// Created by 15854 on 2/11/2024.
//

#include "vec.h"
#include <string.h>
#include <stdio.h>

typedef struct vector_data vector_data;

struct vector_data
{
    vec_size_t alloc; // stores the number of bytes allocated
    vec_size_t length;
    char buff[]; // use char to store bytes of an unknown type
};

vector_data* vector_alloc(vec_size_t alloc, vec_size_t size)
{
    vector_data* v_data = (vector_data*)
            malloc(sizeof(vector_data) + alloc * size);
    v_data->alloc = alloc;
    return v_data;
}

vector_data* vector_get_data(vector vec) { return &((vector_data*)vec)[-1]; }


void vec_union2(vec_int vec1, vec_int vec2) {



        for(int i = 0; i < vector_size(vec2); i++)
        {
            vector_add(&vec1, vec2[i]);
        }


    forceremoveduplicates(vec1);
}


// union concatenates two vecs without duplicates .. kinda like a  set
vec_int vec_union(vec_int vec1, vec_int vec2) {
    int s1 = vector_size(vec1);
    int s2 = vector_size(vec2);


    if(s1 == 0)
    {

        return forceremoveduplicates(vec2);// i am done

    }
    else
    {
        for(int i = 0; i < s2; i++)
        {
            bool exists = false;
            for (int j = 0; j < s1; j++)
            {
                if(vec1[j] == vec2[i])
                    exists = true;
            }
            if(!exists)
                vector_add(&vec1, vec2[i]);
        }

          forceremoveduplicates(vec1);

    }

}

int compare (const void *a, const void *b)
{
    const int *ia = (const int *)a; // casting pointer types
    const int *ib = (const int *)b;
    return *ia  - *ib;
}
vec_int forceremoveduplicates(vec_int x) {


    vec_int y = vector_create();
    if (vector_size(x) > 1) {
        qsort(x, vector_size(x), sizeof(int), compare);
        for (int i = 0; i < vector_size(x); i++)
        {
            if(x[i] != x[i+1])
                vector_add(&y, x[i]);
        }
        //adds last element
        if(x[vector_size(x)-1] != x[vector_size(x)-2])
            vector_add(&y, x[vector_size(x)-1]);

        return y;

    }
    else
    {
        return x;
    }

}
void vec_clear(vector* x)
{
    while( vector_size(x) > 0)
    {
        vector_remove(&x, 0);
    }
}

vector vector_create(void)
{
    vector_data* v = (vector_data*)malloc(sizeof(vector_data));
    v->alloc = 0;
    v->length = 0;

    return &v->buff;
}

void vector_free(vector vec) { free(vector_get_data(vec)); }

vec_size_t vector_size(vector vec) { return vector_get_data(vec)->length; }

vec_size_t vector_get_alloc(vector vec) { return vector_get_data(vec)->alloc; }

vector_data* vector_realloc(vector_data* v_data, vec_type_t type_size)
{
    vec_size_t new_alloc = (v_data->alloc == 0) ? 1 : v_data->alloc * 2;
    vector_data* new_v_data = (vector_data*)
            realloc(v_data, sizeof(vector_data) + new_alloc * type_size);
    new_v_data->alloc = new_alloc;
    return new_v_data;
}

bool vector_has_space(vector_data* v_data)
{
    return v_data->alloc - v_data->length > 0;
}

void* _vector_add(vector* vec_addr, vec_type_t type_size)
{
    vector_data* v_data = vector_get_data(*vec_addr);

    if (!vector_has_space(v_data))
    {
        v_data = vector_realloc(v_data, type_size);
        *vec_addr = v_data->buff;
    }

    return (void*)&v_data->buff[type_size * v_data->length++];
}


void _vector_erase(vector* vec_addr, vec_type_t type_size, vec_size_t pos,
                   vec_size_t len)
{
    vector_data* v_data = vector_get_data(*vec_addr);
    // anyone who puts in a bad index can face the consequences on their own
    memmove(&v_data->buff[pos * type_size],
            &v_data->buff[(pos + len) * type_size],
            (v_data->length - pos - len) * type_size);

    v_data->length -= len;
}

void _vector_remove(vector* vec_addr, vec_type_t type_size, vec_size_t pos)
{
    _vector_erase(vec_addr, type_size, pos, 1);
}


vector _vector_copy(vector vec, vec_type_t type_size)
{
    vector_data* vec_data = vector_get_data(vec);
    size_t alloc_size = sizeof(vector_data) + vec_data->length * type_size;
    vector_data* v = (vector_data*)malloc(alloc_size);
    memcpy(v, vec_data, alloc_size);
    return (void*)&v->buff;
}

