#include "gp.h"

void gt::add(gp &temp)
{
    float a = temp.get_mr();
    float b = temp.get_mc();
    mairu += a;
    maichu += b;
    heji = mairu - maichu;
}

void gt::add(float a,float b)
{
    mairu += a;
    maichu += b;
    heji = mairu - maichu;
}