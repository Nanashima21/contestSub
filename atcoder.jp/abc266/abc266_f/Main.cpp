#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

vector<vector<int>> g;
vector<bool> flag;
set<int> se;
int st=-1;
bool check=false;

void dfs(int pos,int par=-1) {
    flag[pos]=true;
    for(auto nv:g[pos]) {
        if(nv==par) continue;
        if(check) continue;
        if(flag[nv]) {
            st=nv; check=true;
            se.insert(pos);
        } else dfs(nv,pos);
    }
    if(check) {
        se.insert(pos);
        if(st==pos) check=false;
        return;
    }
}

struct UnionFind {
    vector<ll> v;
    UnionFind(ll n=0): v(n,-1) {}
    int find(ll x) {
        if(v[x]<0) return x;
        return v[x]=find(v[x]);
    }
    bool unite(ll x,ll y) {
        x=find(x);
        y=find(y);
        if(x==y) return false;
        if(v[x]>v[y]) swap(x,y);
        v[x]+=v[y];
        v[y]=x;
        return true;
    }
    bool same(ll x,ll y) { return find(x)==find(y); }
    ll size(ll x) { return -v[find(x)]; }
    //UnionFind uf(n);
};

int main() {
    ll n;
    cin >> n;
    vector<int> u(n),v(n);
    g.resize(n,vector<int> ());
    flag.resize(n,false);
    rep(i,n) {
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    dfs(0);
    UnionFind uf(n);
    rep(i,n) {
        if(se.find(u[i])!=se.end()&&se.find(v[i])!=se.end()) continue;
        else uf.unite(u[i],v[i]);
    }
    int q;
    cin >> q;
    rep(i,q) {
        int x,y;
        cin >> x >> y;
        x--; y--;
        cout << (uf.same(x,y) ? "Yes" : "No") << '\n';
    }
    return 0;
}