#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
typedef pair<int, int> pii;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
//double 型memset最大127，最小128
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const double eps=1e-9;
const int N = 3e5 + 10;

void mysolve()
{
	string s;
	int n;
	cin>>n>>s;
	map<char,int>mp;
	vector<char>v;
	for(int i=0; i<n; ++i)
		{
			mp[s[i]]++;
			if(v.size()==1)
				{
					if(mp[s[i]]==7)
						{
							v.push_back(s[i]);
							mp.clear();
						}
					else continue;
				}

			if(mp[s[i]]==5)
				{
					v.push_back(s[i]);
					mp.clear();
				}
			if(v.size()==3)break;
		}
	if(v.size()==3)
		{
			for(int j=0; j<3; ++j)
				{
					if(j!=1)
						for(int i=0; i<5; ++i)cout<<v[j];
					else for(int i=0; i<7; ++i)cout<<v[j];
				}
		}
	else cout<<"none"<<endl;

}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
