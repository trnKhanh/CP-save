#include <bits/stdc++.h>
#include <memory>
#define int long long
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 

// using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
// typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;


const ll inf = 1e9;
const ll Nmax = 1e6+5;
const ll MOD = 1e9+7;
const long double eps = 1e-18;

template<class T>
T _abs(T a)
{
    if(a<0)return -a;else return a;
}
ll _pow(ll x,ll t)
{
    if(t==0)return 1;
    ll tmp=_pow(x,t/2);
    if(t%2)return tmp*tmp%MOD*x%MOD;else return tmp*tmp%MOD;
}
ll _gcd(ll a,ll b)
{
    if(b)return _gcd(b,a%b);else return a;
}

bool checkComplete(vector<vector<int> > &adj)
{
    int n = adj.size() - 1;
    for (int i = 1; i <= n; ++i)
    {
        if (adj[i].size() != n - 1) return 0;
    }
    return 1;
}
bool dfs(int u, vector<int> &col, vector<vector<int> > &adj)
{
    if (col[u] == -1) col[u] = 0;
    for (int i = 0; i < adj[u].size(); ++i)
    {
        int v = adj[u][i];
        if (col[v] != -1 && col[u] == col[v]) return 0;
        if (col[v] == -1)
        {
            col[v] = col[u] ^ 1;
            if (dfs(v, col, adj) == 0) return 0;
        }
    }
    return 1;
}
bool checkBi(vector<vector<int> > &adj)
{
    int n = adj.size() - 1;
    queue<int> q;
    vector<int> col(n+1, -1);
    for (int i = 1; i <= n; ++i)
    {
        if (col[i] == -1)
        {
            if (dfs(i, col, adj) == 0) return 0;
        }
    }
    return 1;
}
bool checkCircular(vector<vector<int> > &adj)
{
    int n = adj.size() - 1;
    for (int i = 1; i <= n; ++i)
    {
        if (adj[i].size() != 2) return 0;
    }
    int cnt = 0, u = 1, pre = -1;
    do {
        ++cnt;
        for (int i = 0; i < adj[u].size(); ++i)
        {
            int v = adj[u][i];
            if (v != pre)
            {
                pre = u;
                u = v;
                break;
            }
        }
    } while (u != 1);
    return (cnt == n);
}
bool checkBiComplete(vector<vector<int> > &adj)
{
    int n = adj.size() - 1;
    queue<int> q;
    vector<int> col(n+1, -1);
    for (int i = 1; i <= n; ++i)
    {
        if (col[i] == -1)
        {
            if (dfs(i, col, adj) == 0) return 0;
        }
    }
    int cnt1 = 0;
    for (int i = 1; i <= n; ++i)
        cnt1 += col[i];
    for (int i = 1; i <= n; ++i)
    {
        if (col[i] == 1 && adj[i].size() != (n - cnt1)) return 0;
        if (col[i] == 0 && adj[i].size() != cnt1) return 0;
    }
    return 1;
}
pair<int,int> DFS(int u, vector<vector<int> > &adj, vector<int> &visited)
{
    visited[u] = 1;
    pair<int,int> res = {1, adj[u].size()};
    for (int i = 0; i < adj[u].size(); ++i)
    {
        int v = adj[u][i];
        if (visited[v]) continue;
        pair<int,int> tmp = DFS(v, adj, visited);
        res.first += tmp.first;
        res.second += tmp.second;
    }
    return res;
}
void countComponent(vector<vector<int> > &adj)
{
    int n = adj.size() - 1;
    vector<int> visited(n + 1, 0);
    int component = 0, tree = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (visited[i]) continue;
        pair<int,int> tmp = DFS(i, adj, visited);
        ++component;
        if (tmp.second / 2 == tmp.first - 1) ++tree;
    }
    cout << "Found " << component << " components and " << tree << " trees\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("text/input.txt","r",stdin);
        freopen("text/output.txt","w",stdout);
    #endif //ONLINE_JUDGE
    int T=1;
    // cin>>T;
    while(T--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > adj(n + 1);
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << checkBi(adj) << ": bigraph\n";
        cout << checkBiComplete(adj) << ": complete bigraph\n";
        cout << checkCircular(adj) << ": circular graph\n";
        cout << checkComplete(adj) << ": complete graph\n";
        countComponent(adj);
    }
    return 0;
}
