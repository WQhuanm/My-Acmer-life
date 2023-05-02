#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const int N = 2e6 + 10;

void mysolve()
{
	int n,k;
	string s="";
	cin>>n>>k;
	vector<int>x(k+1,0),c(k+1,0);
	for(int i=1; i<=k; ++i)cin>>x[i];
	bool flag=1;
	for(int i=1; i<=k; ++i)
		{
			cin>>c[i];
			if(c[i]-c[i-1]>x[i]-x[i-1]||c[i]>x[i])flag=0;//不合法
		}
	if(!flag)
		{
			cout<<"NO"<<endl;
			return;
		}
	string add;
	while((int)add.size()<n)add+="abc";
	int st=0;
	char e='c';
	for(int i=1; i<=k; ++i)
		{
			if(i==1)
				{
					s+="ab";//先把abc用了，后面凑他就没有贡献
					s+=string(c[1]-2,e++);
					int len=x[1]-(int)s.size();
					s+=add.substr(st,len),st+=len;
					continue;
				}
			s+=string(c[i]-c[i-1],e++);
			int len=x[i]-(int)s.size();
			s+=add.substr(st,len),st+=len;
		}
	int len=n-(int)s.size();
	s+=add.substr(st,len),st+=len;
	cout<<"YES"<<endl;
	cout<<s<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
