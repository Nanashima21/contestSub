#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

ll n,m;
vector<vector<int>> g;
vector<int> c;

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
    cin >> n >> m;
    g.resize(n,vector<int> ());
    vector<int> v(m),u(m);
    rep(i,m) {
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
    }
    c.resize(n);
    rep(i,n) cin >> c[i];
    UnionFind uf(n);
    rep(i,m) {
        if(c[u[i]]!=c[v[i]]) uf.unite(u[i],v[i]);
    }
    rep(i,m) {
        if(c[u[i]]==c[v[i]])  {
            if(uf.same(u[i],v[i])) {
                cout << "Yes" << endl;
                return 0;
            } 
        }
    }
    cout << "No" << endl;
    return 0;
}