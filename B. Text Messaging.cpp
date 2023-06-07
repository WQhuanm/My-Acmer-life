#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
inline int read(int &x);
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e5 + 10;
const int mod = 998244353;
string s;
void mysolve()
{
	int n;

	cin>>n;
	getchar();
	getline(cin,s);
	vector<int>v;
	for(int i=0; i<(int)s.size(); ++i)if(s[i]=='.'||s[i]=='?'||s[i]=='!')v.push_back(i);
	if(!(int)v.size())
		{
			if((int)s.size()<n)
				{
					cout<<1<<endl;
				}
			else cout<<"Impossible"<<endl;
		}

	vector<int>a;
	a.push_back(0);
	for(int i=0; i<(int)v.size(); ++i)
		{
			if(i==0)a.push_back(v[i]+1);
			else a.push_back(v[i]-v[i-1]-1);
			if(a.back()>n)
				{
					cout<<"Impossible"<<endl;
					return;
				}
		}

	int len=(int)a.size()-1;
	int cnt=1,p=0;
	for(int i=1; i<=len; ++i)
		{
			if(a[i]+(p?p+1:0)<=n)p=a[i]+(p?p+1:0);
			else p=a[i],cnt++;
		}
	cout<<cnt<<endl;

}

int32_t main()
{
//	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	//cin >> t;
	//read(t);
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

inline int read(int &x)
{
	x = 0;
	char ch = 0;
	while (ch < '0' || ch > '9')ch = getchar();
	while (ch >= '0' && ch <= '9')
		{
			x = x * 10 + ch - '0';
			ch = getchar();
		}
	return x;
}
