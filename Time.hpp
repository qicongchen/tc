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
    friend std::ostream & operator<< (std::ostream & output, const Time &t)
    {
        output<<t.month<<"_"<<t.day<<endl;
        return output;
    }
};


