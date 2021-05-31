                                                                   //author rhythmicankur
                                                                 //god_is_almighty
#pragma GCC optimize("O3")

#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fori(a,b,c) for(register int i=a;i<b;i+=c)
#define ford(a,b,c) for(register int i=a;i>=b;i-=c)
#define PI acos(-1)
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define M1 998244353
#define M2 1000000007
const int  inf = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
#define test4(x,y,z,a) cout<<"x is "<<x<<"        y is "<<y<<"        z is "<<z<<"        a is "<<a<<endl;
#define test3(x,y,z) cout<<"x is "<<x<<"        y is "<<y<<"        z is "<<z<<endl;
#define test2(x,y) cout<<"x is "<<x<<"        y is "<<y<<endl;
#define test1(x) cout<<"x is "<<x<<endl
ll power(ll a,ll b,ll m=M2){ll answer=1;while(b){if(b&1)answer=(answer*a)%m;b/=2;a=(a*a)%m;}return answer;}
using namespace std;
void ctrl()
{
	cout<<"Control\n";
}


int val=1;

int main()
{	
	string p;
	cin>>p;
	
	string q;
	cin>>q;
	
	int trie[1100][26]={-1};
	
	bool chk[26];
	
	for(int i=0;i<26;i++)
	chk[i]=q[i]-'0';
	
	int mx,ans=0;
	cin>>mx;
	set<string>st;
	
	for(int i=0;i<p.length();i++)
	{
		int vert=0,cnt=0;
		for(int j=i;j<p.length();j++)
		{
			int h=p[j]-'a';
			if(!chk[h])
			cnt++;
			
			if(cnt>mx)
			break;
			
			if(trie[vert][h]==-1)
			{
				ans++;
				trie[vert][h]=val;
				val++;
			}
			
			vert=trie[vert][h];
		}
	}
	
	cout<<ans;

return 0;
}

//https://codeforces.com/contest/271/problem/D;
/* trie hasbeen made up of substrings*/
