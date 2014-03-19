#include "Time.hpp"
const int FEATURE_NUM=4;
class Feature
{
public:
    int label;
    double dim[FEATURE_NUM];
    Feature()
    {
        memset(dim,0,sizeof(dim));
    }
    friend std::ostream & operator<< (std::ostream & output, const Feature &f)
    {
        output<<f.label<<" ";
        for(int i=0;i<FEATURE_NUM;i++)
            output<<i<<':'<<f.dim[i]<<" ";
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
