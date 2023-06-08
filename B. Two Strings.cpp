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

bool b[30],c[30];
vector<int>v[30];
int l[N],r[N];
void mysolve()
{
	string s,t,a;
	cin>>s>>t;
	t="$"+t+"$";
	int n=(int)t.size();
	for(int i=1; i<n-1; ++i)
		{
			int c=t[i]-'a';
			v[c].push_back(i);
		}
	int p=1;
	for(int i=0; i<(int)s.size(); ++i)
		{
			if(s[i]==t[p])p++;
			int c=s[i]-'a';
			if(!v[c].empty()&&v[c][0]<p)l[i]=*prev(lower_bound(v[c].begin(),v[c].end(),p));
			else l[i]=-1;
		}
	p=n-2;
	for(int i=(int)s.size()-1; ~i; --i)
		{
			if(s[i]==t[p])p--;
			int c=s[i]-'a';
			if(!v[c].empty()&&v[c][(int)v[c].size()-1]>p)r[i]=n+1-*upper_bound(v[c].begin(),v[c].end(),p);
			else r[i]=-1;
		}
	for(int i=0; i<(int)s.size(); ++i)
		{
			if(l[i]+r[i]<n+1)
				{
					cout<<"NO"<<endl;
					return;
				}
		}
	cout<<"YES"<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
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
