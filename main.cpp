#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include "stringtotime/time_string.h"
#include "gp/gp.h"
using namespace std;

vector<string> split(const string &str, const string &pattern)
{
    vector<string> ret;
    if (pattern.empty())
        return ret;
    size_t start = 0, index = str.find_first_of(pattern, 0);
    while (index != str.npos)
    {
        if (start != index)
        {
            ret.push_back(str.substr(start, index - start));
        }
        start = index + 1;
        index = str.find_first_of(pattern, start);
    }
    if (!str.substr(start).empty())
    {
        ret.push_back(str.substr(start));
    }
    return ret;
}

template <class T>
T stringToNum(const string &str)
{
    istringstream iss(str);
    T num;
    iss >> num;
    return num;
}

int main()
{
    vector<hgt> hgt_t;
    vector<sgt> sgt_t;
    vector<gt> gt_t;
    string xx = "[]";
    ifstream file("2020-07-11_2021-07-11.txt");
    string temp;
    if (!file.is_open())
    {
        cout << "未打开文件" << endl;
        return -1;
    }
    while (getline(file, temp))
    {
        vector<string> temp_sj = split(temp, xx);
        long time_temp = StringToDatetime(temp_sj[0]);
        float M1 = stringToNum<float>(string(temp_sj[2]));
        float M2 = stringToNum<float>(string(temp_sj[3]));
        if (temp_sj[1] == "shhk")
        {
            hgt_t.push_back(hgt(time_temp, M1, M2));
        }
        else if (temp_sj[1] == "szhk")
        {
            sgt_t.push_back(sgt(time_temp, M1, M2));
        }
        if (gt_t.size() == 0||gt_t.back().time_size() != time_temp)
        {
            gt_t.push_back(gt(time_temp, M1, M2));
        }
        else
        {
            gt_t.back().add(M1, M2);
        }
    }

    file.close();

    sort(gt_t.begin(), gt_t.end());

    cout<<gt_t[gt_t.size()/3].hj_size()<<endl;
    cout<<gt_t[gt_t.size()/3*2].hj_size()<<endl;
    

    

    return 0;
}