#include "Query.hpp"
#include "malloc.hpp"
#include <cmath>
#include <fstream>
using namespace std;


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

void ReadData(int p1, int p2)
{
	string s;
	ifstream fin("data.txt");
	vector<string> components;
	int line=0;
	// Time aug = Time(8,1);
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
		// feature extraction

		// if (action==1)
		// {
		// 	if (qList[uid].features[pos].second.saved==1)
		// 		qList[uid].features[pos].second.dim[9]=1;
		// 	qList[uid].features[pos].second.bought = 1;
		// 	qList[uid].features[pos].second.dim[6]=1;
		// }

		// if (action==2 || action==3)
		// {
		// 	if (qList[uid].features[pos].second.bought==1)
		// 		qList[uid].features[pos].second.dim[8]=1;
		// 	qList[uid].features[pos].second.saved = 1;
		// 	qList[uid].features[pos].second.dim[7]=1;

		// }

		qList[uid].features[pos].second.dim[action]++;
		qList[uid].features[pos].second.label = (action==1)?1:-1;
		qList[uid].features[pos].second.time = t;
		Time minold = qList[uid].features[pos].second.min;
		qList[uid].features[pos].second.min = (minold>t)?t:minold;
		double spanold = qList[uid].features[pos].second.span;
		double spannew = t-qList[uid].features[pos].second.min;
		qList[uid].features[pos].second.dim[4] = (spannew>spanold)?spannew:spanold;

	}

	cout<<"reading "<<line<<" lines!"<<endl;
	cout<<"user num : "<<id2ukey.size()<<endl;
	cout<<"goods num : "<<id2gkey.size()<<endl;
	fin.close();
	ofstream f1f("train.features");
	ofstream f1l("train.labels");
	ofstream f1q("train.qids");
	ofstream f1e("train.allids");
	ofstream f2f("test.features");
	ofstream f2l("test.labels");
	ofstream f2q("test.qids");
	ofstream f2e("test.allids");
	// ofstream f("1:all");
	// ofstream f3f("testoffline.features");
	// ofstream f3l("testoffline.labels");
	// ofstream f3q("testoffline.qids");
	// ofstream f3e("testoffline.allids");
	// cout<<"qlist size:"<<qList.size()<<"  half:"<<qList.size()/2<<endl;

	for (int i = 0;i<id2ukey.size();i++)
	{
		Query& q = qList[i];
		int size = qList[i].features.size();
		int r = size%(p1+p2);
		int ratio_size = (r==0)?size*p1/(p1+p2):(size-r)*p1/(p1+p2);
		if (ratio_size==0) ratio_size=1;
		pair<int,Feature> p;
		for(int j=0;j<ratio_size;j++)
		{
			p=q.features[j];
			int eid = q.pos2eid(j);
			// if (p.second.time>aug)
			// {
			// 	f3e<<eid<<'	'<<id2gkey[eid]<<'	'<<id2ukey[i]<<endl;
			// 	f3f<<p.second;
			// 	f3l<<p.second.label<<endl;
			// 	f3q<<i<<endl;
			// }
			// else
			// {
				p.second.dim[5]=p.second.dim[1]/(p.second.dim[0]+p.second.dim[1]+p.second.dim[2]+p.second.dim[3]);
				p.second.dim[6]=(p.second.dim[1]>3)?1:0;
				f1e<<eid<<'	'<<id2gkey[eid]<<'	'<<id2ukey[i]<<endl;
				// f1f<<p3<<':'<<p.second.dim[p3]<<" "<<endl;
				f1f<<p.second;
				f1l<<p.second.label<<endl;
				// f<<p.second.dim[1]<<"\t"<<(p.second.dim[0]+p.second.dim[1]+p.second.dim[2]+p.second.dim[3])<<"\n";
				f1q<<i<<endl;
			// }
		}
		if (size == 1) ratio_size = 0;
		for(int k=ratio_size;k<size;k++)
		{
			p=q.features[k];
			int eid = q.pos2eid(k);
			// if (p.second.time>aug)
			// {
			// 	f3e<<eid<<'	'<<id2gkey[eid]<<'	'<<id2ukey[i]<<endl;
			// 	f3f<<p.second;
			// 	f3l<<p.second.label<<endl;
			// 	f3q<<i<<endl;
			// }
			// else
			// {
				p.second.dim[5]=p.second.dim[1]/(p.second.dim[0]+p.second.dim[1]+p.second.dim[2]+p.second.dim[3]);
				p.second.dim[6]=(p.second.dim[1]>3)?1:0;
				f2e<<eid<<'	'<<id2gkey[eid]<<'	'<<id2ukey[i]<<endl;
				// f2f<<p3<<':'<<p.second.dim[p3]<<" "<<endl;
				f2f<<p.second;
				f2l<<p.second.label<<endl;
				f2q<<i<<endl;
				// f<<p.second.dim[1]<<"\t"<<(p.second.dim[0]+p.second.dim[1]+p.second.dim[2]+p.second.dim[3])<<"\n";
			// }
		}

	}

	f1f.close();
	f1l.close();
	f1q.close();
	f1e.close();
	f2e.close();
	f2f.close();
	f2l.close();
	f2q.close();
	// f.close();
	// f3e.close();
	// f3f.close();
	// f3l.close();
	// f3q.close();
}

int main(int argc,char** argv)
{

	// SortByTime();
	int p1 = atoi(argv[1]);
	int p2 = atoi(argv[2]);
	// int p3 = atoi(argv[3]);
	cout<<"train:test is "<<p1<<":"<<p2<<endl;
	ReadData(p1,p2);
	return 0;
}
