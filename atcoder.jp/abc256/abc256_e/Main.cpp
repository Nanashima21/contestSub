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
    ll n;
    cin >> n;
    vector<ll> x(n),c(n);
    rep(i,n) cin >> x[i];
    rep(i,n) cin >> c[i];
    vector<pair<int,int>> p;
    vector<vector<int>> g(n,vector<int> ());
    rep(i,n) {
        p.push_back({i,x[i]-1});
        g[i].push_back(x[i]-1);
    }
    UnionFind uf(n);
    vector<ll> v;
    rep(i,n) {
        if(uf.same(p[i].first,p[i].second)) v.push_back(p[i].first);
        else uf.unite(p[i].first,p[i].second);
    }
    vector<bool> flag(n,false);
    ll ans=0;
    rep(i,(int)v.size()) {
        queue<int> q;
        q.push(v[i]);
        flag[v[i]]=true;
        ll mi=c[v[i]];
        while(!q.empty()) {
            int cv=q.front();
            q.pop();
            for(auto nv:g[cv]) {
                if(flag[nv]) continue;
                flag[nv]=true;
                q.push(nv);
                mi=min(mi,c[nv]);
            }
        }
        ans+=mi;
    }
    cout << ans << endl;
    return 0;
}