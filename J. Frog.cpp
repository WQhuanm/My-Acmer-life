#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define eps 1e-7
const int mod = 998244353;

#define pi acos(-1)

struct node
{
	double x,y;
};

void mysolve()
{
	double s,t;
	cin>>s>>t;
	vector<node>ans;
	double q2=sqrt(2);
	ans.push_back({cos(s*pi/180),sin(s*pi/180)});
	if(fabs(t-s)<eps)
		{
			cout<<0<<endl;
			for(node v:ans)printf("%.10lf %.10lf\n",v.x,v.y);
			return;
		}
	else
		{
			double jud=cos(s*pi/180)*sin(t*pi/180)-cos(t*pi/180)*sin(s*pi/180);
			bool flag=0;
			if(jud>0)flag=1;//逆时针
			double f=(fabs(s-t)),fl=f*pi/180;
			double r=s*pi/180;
			if(f<=90)
				{
					cout<<2<<endl;
					double dis=2*cos(fl/2.0);
					if(flag)r+=fl/2;
					else r-=fl/2;
					ans.push_back({dis*cos(r),dis*sin(r)});

				}
			else if(f<=90+acos(0.75)*180/pi)
				{
					cout<<3<<endl;
					if(flag)r+=pi/4;
					else r-=pi/4;
					ans.push_back({sqrt(2)*cos(r),sqrt(2)*sin(r)});

					double fd=fl-pi/4;
					double len=sqrt(3-2*sqrt(2)*cos(fd));
					double p1=acos((len*len+1.0)/(2.0*sqrt(2)*len));
					p1+=acos(len*1.0/2.0);
					double dis=sqrt(3-2*sqrt(2)*cos(p1));
					double dr=acos((dis*dis+1.0)/(2*q2*dis));
					if(flag)r+=dr;
					else r-=dr;
					ans.push_back({dis*cos(r),dis*sin(r)});
				}
			else
				{
					cout<<4<<endl;
					if(flag)r+=pi/4;
					else r-=pi/4;
					ans.push_back({q2*cos(r),q2*sin(r)});

					if(flag)r+=pi/4;
					else r-=pi/4;
					ans.push_back({cos(r),sin(r)});

					fl-=pi/2;
					double dis=2*cos(fl/2);
					if(flag)r+=fl/2;
					else r-=fl/2;
					ans.push_back({dis*cos(r),dis*sin(r)});
				}
			ans.push_back({cos(t*pi/180),sin(t*pi/180)});
			for(node v:ans)printf("%.10lf %.10lf\n",v.x,v.y);
		}
}

int32_t main()
{
	int t=1;
	cin >> t;
	while (t--)mysolve();
	system("pause");
	return 0;
}

