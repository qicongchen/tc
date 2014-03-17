#include "Time.hpp"
const int FEATURE_NUM=4;
class Feature
{
public:
    double dim[FEATURE_NUM];
    Feature()
    {
        memset(dim,0,sizeof(dim));
    }
    friend std::ostream & operator<< (std::ostream & output, const Feature &f)
    {
        for(int i=0;i<FEATURE_NUM;i++)
            output<<f.dim[i]<<" ";
        output<<endl;
        return output;
    }
};
class Query
{
public:

        map<int,int> m;
        vector<pair<int,Feature> > features;
        Query(){};
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

};
