#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
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
    ll n,m;
    cin >> n >> m;
    UnionFind uf(n);
    vector<pl> p;
    vector<ll> cnt(n,-1);
    rep(i,m) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        uf.unite(u,v);
        p.push_back({u,v});
    }
    rep(i,n) cnt[uf.find(i)]=0;
    rep(i,m) cnt[uf.find(p[i].first)]++;
    bool flag=true;
    rep(i,n) {
        //cout << cnt[i] << " " << uf.size(i) << endl;
        if(cnt[i]!=-1) {
            if(uf.size(i)!=cnt[i]) flag=false;
        } 
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}