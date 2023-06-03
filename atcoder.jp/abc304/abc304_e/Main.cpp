#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

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
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n,vector<int> ());
    UnionFind uf(n);
    rep(i,m) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
        uf.unite(u,v);
    }
    set<pair<int,int>> se;
    int k;
    cin >> k;
    rep(i,k) {
        int x,y;
        cin >> x >> y;
        x--; y--;
        se.insert({uf.find(x),uf.find(y)});
        se.insert({uf.find(y),uf.find(x)});
    }
    int q;
    cin >> q;
    while(q--) {
        int p,q;
        cin >> p >> q;
        p--; q--;
        bool flag=true;
        if(se.find({uf.find(p),uf.find(q)})!=se.end()) flag=false;
        cout << (flag ? "Yes" : "No") << "\n";
    }
    return 0;
}