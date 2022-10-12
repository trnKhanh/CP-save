#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <string.h>
#define DEBUG "BUG!!!!\n"
#define int long long
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 

//using namespace __gnu_pbds;
using namespace std;

const long long inf = 1e18;
const long long Nmax = 3e5+5;
const long long MOD = 1e9+7;
const long double eps = 1e-18;

//typedef tree<long long,null_type,less<long long32_t>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
long long ab(long long a)
{
    if(a<0)return -a;else return a;
}
long double ab(long double a)
{
    if(a+eps<0)return -a;else return a;
}
long long POW(long long x,long long t)
{
    if(t==0)return 1;
    long long tmp=POW(x,t/2);
    if(t%2)return tmp*tmp%MOD*x%MOD;else return tmp*tmp%MOD;
}
long long gcd(long long a,long long b)
{
    if(b)return gcd(b,a%b);else return a;
}
struct node{
    vector<pair<int,int> >v;
};
int p[Nmax],a[Nmax];
vector<node>f;
void build(int id, int l, int r)
{
    if(l==r)
    {
        f[id].v.push_back({a[l],p[l]});
        return;
    }
    int mid=(l+r)>>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    int j=0;
    for(int i=0;i<f[id*2].v.size();++i)
    {
        while(j<f[id*2+1].v.size()&&f[id*2+1].v[j]<f[id*2].v[i])
            f[id].v.push_back(f[id*2+1].v[j++]);
        f[id].v.push_back(f[id*2].v[i]);
    }
    while(j<f[id*2+1].v.size())
        f[id].v.push_back(f[id*2+1].v[j++]);
}
void update(int id,int l,int r)
{
    if(l==r)return;
    int mid=(l+r)>>1;
    update(id*2,l,mid);
    update(id*2+1,mid+1,r);
    for(int i=(int)f[id].v.size()-1;i>=0;i--)
    {
        (f[id].v[i].second+=f[id].v[i+1].second)%=MOD;
    }
}
pair<int,int> query(int id,int l,int r,int x,int y,int k)
{
    if(y<l||r<x)return {0,0};
    if(x<=l&&r<=y)
    {
        pair<int,int>res;
        res.first=upper_bound(f[id].v.begin(),f[id].v.end(),make_pair(k,0ll))-f[id].v.begin();
        if(res.first<f[id].v.size())res.second=f[id].v[res.first].second;else res.second=0;
        return res;
    }
    int mid=(l+r)>>1;
    pair<int,int>L=query(id*2,l,mid,x,y,k);
    pair<int,int>R=query(id*2+1,mid+1,r,x,y,k);
    return {L.first+R.first,L.second+R.second};
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input","r",stdin);
    int T=1;
    //cin>>T;
    while(T--)
    {
        int n,q;
        cin>>n>>q;
        f.resize(n*4);
        for(int i=1;i<=n;i++)cin>>a[i];
        p[n]=1;
        for(int i=n-1;i>=1;i--)p[i]=(p[i+1]*(n-i))%MOD;
        build(1,1,n);
        update(1,1,n);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            (ans+=query(1,1,n,i+1,n,a[i]).first*p[i]%MOD)%MOD;
        }
        for(int i=0;i<q;i++)
        {
            int l,r;
            cin>>l>>r;
            int res=0;
            int tmpr=query(1,1,n,r+1,n,a[r]).first;
            res-=tmpr*p[r]%MOD;
            tmpr=query(1,1,n,l+1,n,a[r]).first+(a[l]<a[r]);
            res+=tmpr*p[l]%MOD;
            int tmpl=query(1,1,n,r+1,n,a[l]).first;
            res+=tmpl*p[r]%MOD;
            tmpl=query(1,1,n,l+1,n,a[l]).first;
            res-=tmpl*p[l]%MOD;
            res-=query(1,1,n,l+1,r-1,a[r]).second%MOD;
            res+=query(1,1,n,l+1,r-1,a[l]).second%MOD;
            res=((res+ans)%MOD+MOD)%MOD;
            cout<<res+1<<endl;
        }
    }
}
//i+1 2i-1
//i 2i-3 
//><<<
