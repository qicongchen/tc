#include "Time.hpp"
const int FEATURE_NUM=7;
class Feature
{
public:

    int label;
    double dim[FEATURE_NUM];//0:0 1:1 2:2 3:3 4:timespan 5:1/0+1+2+3 6:1>3 7:bought 8:saved 9:bs 10:sb
    Time min;
    double span;
    Time time;
    int bought;
    int saved;
    Feature()
    {
        memset(dim,0,sizeof(dim));
    }
    friend std::ostream & operator<< (std::ostream & output, const Feature &f)
    {
        // output<<f.label<<" ";
        for(int i=0;i<FEATURE_NUM;i++)
        {
            // if (i!=2 && i!=3 && i!=4 && i!=6)
            // if (i!=2 && i!=3 )
            // if()
            {
                output<<i<<':'<<f.dim[i]<<" ";
            }
        }
        output<<endl;
        return output;
    }
};
class Query
{
public:
        map<int,int> m;//
        vector<pair<int,Feature> > features;//4 [];9 [];7 []
        Query(){};

        //find the position of an element in a query list of a person given the element id (good)
        int eid2pos(int eid)
        {
            int pos;
            map<int,int>::iterator it=m.find(eid);
            if(it==m.end())
            {
                pos=m.size();
                m.insert(make_pair(eid,pos));
                features.push_back(make_pair(eid,Feature()));

            }
            else
                pos=it->second;
            return pos;
        }

        //find the element id in a query list of a person given the position of an element (good)
        int pos2eid(int pos)
        {
            int eid;
            map<int,int>::iterator it;
            for (it=m.begin();it!=m.end();it++)
            {
                if(it->second==pos)
                {
                    eid = it->first;
                    break;
                }
            }
            return eid;
        }

        //print a whole query
        //  friend std::ostream & operator<< (std::ostream & output, const Query &q)
        // {
        //     pair<int,Feature> p;
        //     for(int i=0;i<q.features.size();i++)
        //     {
        //         p=q.features[i];
        //         output<<p.first<<" "<<p.second;
        //     }

        //     return output;
        // }

};
