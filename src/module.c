/** @file module.c
 *  @brief Example module (source)
 *
 *  This is an example. Please, change the description.
 *
 *  @author Name Surname - xxx@spbstu.ru
 */

#include "module.h"

float sqr(float x)
{
    return x * x;
}

void sqr_arr(float* x,  int size)
{
    while(--size >= 0)
    {
        x[size] = sqr(x[size]);
    }
}

void clear_arr(float* x,  int size)
{
    while(--size >= 0)
    {
        x[size] = 0.0f;
    }
}
