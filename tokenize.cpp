#include "Time.hpp"

vector<string> line_tokenize(string a,string sep)
{
	vector<string> result;
	int start=0,end=0,pos=0,len=sep.length();
	while(a.c_str()[end])
	{
		if(a.c_str()[end]!=sep.c_str()[pos])
		{
			end++;
			if(pos!=0)
				pos=0;
		}
		else
		{
			end++;
			pos++;
			if(pos==len)
			{
				if(end-len-start==0);
					//result.push_back(string(""));
				else
					result.push_back(a.substr(start,end-len-start));
                                start=end;
				pos=0;
			}
		}
	}
	if(end-start==0);
		//result.push_back(string(""));
	else
		result.push_back(a.substr(start,end-start));
	return result;
}
vector< string > component_tokenize(string a,string seps)
	{
		vector<string> b;
		char* sa=new char[200];

		int i=0,j=0;
		for(; i < a.length(); i++,j++)
		{
    			sa[j] = a.at(i);
		}
		sa[j]='\0';


		//strcpy(sa,a.c_str);
		char* token=strtok(sa,seps.c_str());
		while(token)
		{
			a.assign(token);
			b.push_back(a);
			token=strtok(NULL,seps.c_str());
		}
		delete []sa;
		return b;
	}
bool is_number(char c)
{
	if(c<'0'||c>'9')
		return false;
	else
		return true;
}
Time time_tokenize(string a)
{
	int i=0,tmp,month,day;
	while(is_number(a.at(i)))i++;
	month=atoi(a.substr(0,i).c_str());
	while(!is_number(a.at(i)))i++;
	tmp=i;
	while(is_number(a.at(i)))i++;
	day=atoi(a.substr(tmp,i-tmp).c_str());
	return Time(month,day);
}
