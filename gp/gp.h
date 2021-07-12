#pragma once

#include<string>
using namespace std;

class gp
{
protected:
    long time_te;
    string sc_te;
    float mairu;
    float maichu;
    float heji;

public:
    gp(long time, string sc, float mr, float mc)
        : time_te(time), sc_te(sc), mairu(mr), maichu(mc), heji(mr - mc){};
    float hj_size() { return heji; }
    long time_size() { return time_te; }
    bool operator<(const gp &rhs) const { return heji < rhs.heji; }
    bool operator>(const gp &rhs) const { return heji > rhs.heji; }
    float get_mr() { return mairu; }
    float get_mc() { return maichu; }
};

class hgt : public gp
{
private:
    /* data */
public:
    hgt(long time, float mr, float mc, string sc = "shhk")
        : gp(time, sc, mr, mc){};
};

class sgt : public gp
{
private:
    /* data */
public:
    sgt(long time, float mr, float mc, string sc = "szhk")
        : gp(time, sc, mr, mc){};
};

class gt : public gp
{
private:
public:
    gt(long time, float mr, float mc, string sc = "hk")
        : gp(time, sc, mr, mc){};
    void add(gp &temp);
    void add(float a,float b);
};