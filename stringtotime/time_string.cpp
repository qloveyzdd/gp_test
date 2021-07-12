#include "time_string.h"

long StringToDatetime(string str)
{
    char *cha = (char *)str.data();
    int year, month, day;
    sscanf(cha, "%d-%d-%d", &year, &month, &day);
    long t_ = year*10000+month*100+day;
    return t_;
}