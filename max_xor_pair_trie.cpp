                                                                   //author rhythmicankur
                                                                 //god_is_almighty
#pragma GCC optimize("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
#define f first
#define s second
#define ll int
#define int long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define vi vector<int>
#define pii pair<int,int>
#define fori(a,b,c) for(register int i=a;i<b;i+=c)
#define ford(a,b,c) for(register int i=a;i>=b;i-=c)
#define PI acos(-1)
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define M1 998244353
#define M2 1000000007
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

struct trieNode
{
    trieNode* cell[2];
    int cnt=0;
};

struct trieNode* head;

void insert(int x)
{
    struct trieNode* cur=head;

    for(int i=30;i>=0;i--)
    {
        int bit=(x>>i)&1;

        if(cur->cell[bit]==NULL)
        {
            cur->cell[bit]=new struct trieNode();
        }

        cur=cur->cell[bit];

        cur->cnt++;
    }
}

void erase(int x)
{
    struct trieNode* cur=head;

    for(int i=30;i>=0;i--)
    {
        int bit=(x>>i)&1;

        

        cur=cur->cell[bit];

        cur->cnt--;
    }
}

int xort(int x)
{
    struct trieNode* cur=head;
    int s=0;
    for(int i=30;i>=0;i--)
    {
        int bit=(x>>i)&1;

        if(cur->cell[bit^1]!=NULL&&cur->cell[bit^1]->cnt>0)
        {
            s+=(1LL<<i);

            cur=cur->cell[bit^1];
        }
        else

        cur=cur->cell[bit];

        
    }

    return s;
}

signed main()
{	
    head=new struct trieNode();
    insert(0);
	int t;
	cin>>t;
	while(t--)
	{
        char ch;
        cin>>ch;

        int x;
        cin>>x;

        if(ch=='+')
        insert(x);
        else if(ch=='-')
        erase(x);
        else
        {
            cout<<xort(x)<<endl;
        }
        
	
	}

return 0;
}