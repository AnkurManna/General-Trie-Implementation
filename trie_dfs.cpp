                                                                   //author rhythmicankur
                                                                  //god_is_almighty
#pragma GCC optimize("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
#define f 		first
#define s 		second
#define ll 		int
#define int 		long long
#define ld 		long double
#define pb 		push_back
#define eb 		emplace_back
#define mk 		make_pair
#define vi 		vector<int>
#define pii 		pair<int,int>
#define vpi 		vector<pii>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define trav(a, x)      for(auto& a : x)
#define all(x)          x.begin(), x.end()
#define fill(a,val)	memset(a,val,sizeof(a))
#define 	PI acos(-1)
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define M1 	998244353
#define M2 	1000000007
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); } 
#define test4(x,y,z,a) 		    cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<"  |  "<<#a<<": "<<a<<endl;
#define test1(x)                cerr<<#x<<": "<<x<<endl
#define test2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define test3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
ll power(ll a,ll b,ll m=M2){ll answer=1;while(b){if(b&1)answer=(answer*a)%m;b/=2;a=(a*a)%m;}return answer;}
using namespace std;
void ctrl(){cout<<"Control"<<endl;}
int make_num(string p){stringstream geek(p); int x = 0; geek >> x;return x;}
string make_str(int x){ostringstream str1; str1 << x; string geek = str1.str(); return geek;}
int n,k,ans;
class node
{
    public:
    int cnt;
    node* next[26];
    node()
    {
        cnt=0;
        for(int i=0;i<26;i++)next[i]=NULL;
    }
};
void insert(node* head,string p)
{
    node* curr=head;
    for(int i=0;i<p.length();i++)
    {
        int x=p[i]-'A';
            //test1(x);

        if(curr->next[x]==NULL)
        curr->next[x]=new node();

        curr=curr->next[x];
        curr->cnt++;

    }

}
void del(node* head)
{
    if(!head)
    return;

    for(int i=0;i<26;i++)
    del(head->next[i]);

    delete(head);

}
int dfs(node* head)
{
    node* curr=head;

    if(!curr)
    return 0;

    int ans=head->cnt/k;

    for(int i=0;i<26;i++)
    {
        if(curr->next[i])
        {
            ans+=dfs(curr->next[i]);
        }
    }
    return ans;
}
signed main()
{	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin.exceptions(cin.failbit);
	int tc;
	cin>>tc;
	for(int t=1;t<=tc;t++)
	{
        cin>>n>>k;
    
        node* head=new node();
        for(int i=0;i<n;i++)
        {
            string p;
            cin>>p;
            insert(head,p);
        }
        int val=dfs(head);
        cout<<"Case #"<<t<<": "<<val<<'\n';
        del(head);
	}

return 0;
}
//problem link
//https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3ff3