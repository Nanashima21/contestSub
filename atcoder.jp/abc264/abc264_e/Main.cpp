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
    int n,m,e;
    cin >> n >> m >> e;
    vector<pl> p;
    rep(i,e) {
        ll u,v;
        cin >> u >> v;
        u--; v--;
        p.push_back({u,v});
    }
    int q;
    cin >> q;
    vector<ll> x(q);
    vector<bool> flag(e);
    rep(i,q) {
        cin >> x[i];
        x[i]--;
        flag[x[i]]=true;
    }
    vector<ll> ans;
    UnionFind uf(n+1);
    rep(i,e) if(!flag[i]) {
        if(p[i].second<n) uf.unite(p[i].first,p[i].second);
        else if(p[i].first<n&&p[i].second>=n) uf.unite(p[i].first,n);
    }
    ans.push_back(uf.size(n)-1);
    reverse(all(x));
    rep(i,q) {
        ans.push_back(uf.size(n)-1);
        if(p[x[i]].second<n) uf.unite(p[x[i]].first,p[x[i]].second);
        else if(p[x[i]].first<n&&p[x[i]].second>=n)uf.unite(p[x[i]].first,n);
    }
    reverse(all(ans));
    rep(i,q) cout << ans[i] << endl;
    return 0;
}