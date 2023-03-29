#include <bits/stdc++.h>
using namespace std;
#define ll               long long
struct node
{
	string name,card;
	bool ill;
	string time;
	int time_tonum;
	int vis;
	bool operator<(const node&k)const
	{
		return time_tonum<k.time_tonum;
	}
};
set<string>ill;//set判断是否已经录入过这个病人
vector<node>ans;
map<string,int>mp;
int cnt;
int main()
{
	int d,p,t,s;
	cin>>d>>p;
	for (int h=1; h<=d; ++h)
		{
			cin>>t>>s;
			vector<node>a;
			for (int i=1; i<=t; ++i)
				{
					node tmp;
					cin>>tmp.name>>tmp.card>>tmp.ill>>tmp.time;
					if ((int)tmp.card.size()==18)
						{
							bool flag=1;
							for (int j=0; j<18; ++j)if (tmp.card[j]<'0'||tmp.card[j]>'9')flag=0;
							if (flag)//身份证合法时
								{
									tmp.time_tonum=((tmp.time[0]-'0')*10+tmp.time[1]-'0')*60+((tmp.time[3]-'0')*10+tmp.time[4]-'0');
									if (tmp.ill==1&&!ill.count(tmp.card))//如果生病，存入ans里面，并用set标记
										{
											ill.insert(tmp.card);
											ans.push_back(tmp);
										}
									a.push_back(tmp);//合法录入当天可能获得口罩的数组中
								}
						}
				}
			stable_sort(a.begin(),a.end());//要求排序不改变同时提交的相对位置，使用稳定排序，stable_sort
			int k=0;
			for (int j=0; j<(int)a.size(); ++j)
				{
					if (k<s)
						{
							if (mp[a[j].card]+p<h||mp[a[j].card]==0)//发放口中，更新申请日期
								{
									k++;
									cout<<a[j].name<<" "<<a[j].card<<endl;
									mp[a[j].card]=h;
								}
						}
					else break;
				}
		}
	for (auto &k:ans)cout<<k.name<<" "<<k.card<<endl;
	return 0;
}
