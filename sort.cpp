#include "Time.hpp"
#include <utility>
#include <algorithm>

bool compare(const pair<string,Time> &x, const pair<string,Time> &y)
{
    Time tx=x.second;
    Time ty=y.second;
    return tx > ty;
}
extern void sort_pair(vector<pair<string,Time> >& vec)
{
   sort(vec.begin(), vec.end(), compare);
}
