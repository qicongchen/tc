#ifndef TIME_HPP

#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <map>
using namespace std;
class Time
{
public:
    int month;
    int day;
    Time(){}
    Time(int m,int d){month=m,day=d;}

    bool operator>(Time& t2)
    {
        if(month>t2.month)
            return true;
        else if(month<t2.month)
            return false;
        else if(day>t2.day)
            return true;
        else
            return false;
    }

    double operator-(Time& t2)
    {
        double ret;
        if(*this>t2)
            ret=(month-t2.month)*30+day-t2.day;
        else
            ret=(t2.month-month)*30+t2.day-day;
        ret/=150;
        return ret;
    }

    friend std::ostream & operator<< (std::ostream & output, const Time &t)
    {
        output<<t.month<<"_"<<t.day<<endl;
        return output;
    }
};


#endif
