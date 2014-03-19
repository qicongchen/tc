#include "Query.hpp"
#include "malloc.hpp"
#include <cmath>
#include <fstream>

Time MID_TIME;

void sort_pair(vector<pair<string,Time> >& vec);//sort module
vector<string> component_tokenize(string a, string seps);//tokenization module
Time time_tokenize(string a);

map<long,int> umap,gmap;//mapping module
vector<long> id2ukey,id2gkey;

vector<Query> qList;
vector<Query> qList_train;
vector<Query> qList_test;

int key2id(long key, map<long,int> &m,vector<long> &id2key)
{
	map<long,int>::iterator it=m.find(key);
	int id;
	if(it==m.end())
	{
		id=m.size();
		m.insert(make_pair(key,id));
		id2key.push_back(key);
	}
	else
		id=it->second;
	return id;
}
int ukey2id(long key)
{
	return key2id(key,umap,id2ukey);
}
int gkey2id(long key)
{
	return key2id(key,gmap,id2gkey);
}
void  SortByTime()
{
	vector<pair<string,Time> > sort_pool;
	string s;
	ifstream fin("t_alibaba_data.csv");
	vector<string> components;
	int line=0;
	getline(fin,s);//pass the 1st line
	while(getline(fin,s))
	{
		line++;
		components=component_tokenize(s,",");
		Time t=time_tokenize(components[3]);
		sort_pool.push_back(make_pair(s,t));

	}
	cout<<"reading "<<line<<" lines!"<<endl;
	fin.close();

	sort_pair(sort_pool);

	ofstream fout("data.txt");
	for(int i=sort_pool.size()-1;i>=0;i--)
		fout<<sort_pool[i].first<<endl;
	fout.close();
}

void ReadData(int ratio)
{
	string s;
	ifstream fin("data.txt");
	vector<string> components;
	int line=0;
	while(getline(fin,s))
	{
		line++;
		components=component_tokenize(s,",");
		long ukey=atol(components[0].c_str());
		long gkey=atol(components[1].c_str());
		int action=atoi(components[2].c_str());
		Time t=time_tokenize(components[3]);
		//mapping
		int uid=ukey2id(ukey);
		int gid=gkey2id(gkey);
		if(qList.size()<id2ukey.size())
		{
			Query q;
			qList.push_back(q);
		}
		int pos=qList[uid].eid2pos(gid);
		//feature extraction
		qList[uid].features[pos].second.dim[action]++;
		qList[uid].features[pos].second.label = (action==1)?1:0;

		//divided by time
		// if(line>91440)
		// {
		// 	if(qList_test.size()<id2ukey.size())
		// 	{
		// 		Query q;
		// 		qList_test.push_back(q);
		// 	}
		// 	int pos=qList_test[uid].eid2pos(gid);
		// 	qList_test[uid].features[pos].second.dim[action]++;

		// }
		// else
		// {
		// 	if(qList_train.size()<id2ukey.size())
		// 	{
		// 		Query q;
		// 		qList_train.push_back(q);
		// 	}
		// 	int pos=qList_train[uid].eid2pos(gid);
		// 	qList_train[uid].features[pos].second.dim[action]++;

		// }

	}

	cout<<"reading "<<line<<" lines!"<<endl;
	cout<<"user num : "<<id2ukey.size()<<endl;
	cout<<"goods num : "<<id2gkey.size()<<endl;
	fin.close();
	ofstream f1("train.txt");
	ofstream f2("test.txt");
	cout<<"qlist size:"<<qList.size()<<"  half:"<<qList.size()/2<<endl;

	for (int i = 0;i<id2ukey.size();i++)
	{
		Query q = qList[i];
		int size = qList[i].features.size();
		int ratio_size = (size%ratio==0)?size/ratio:(size-size%ratio)/ratio;
		pair<int,Feature> p;
		for(int j=0;j<ratio_size;j++)
		{
			p=q.features[j];
			f1<<p.first<<" "<<p.second;
		}
		for(int k=ratio_size;k<size;k++)
		{
			p=q.features[k];
			f2<<p.first<<" "<<p.second;
		}

	}

	f1.close();
	f2.close();
}

int main(int argc,char** argv)
{

	// SortByTime();
	ReadData(4);
	return 0;
}
