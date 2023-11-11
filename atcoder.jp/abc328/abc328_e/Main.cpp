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
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> u(m),v(m),w(m); 
    vector<vector<vector<ll>>> g(n,vector<vector<ll>> (n,vector<ll> ()));
    rep(i,m) {
        cin >> u[i] >> v[i] >> w[i];
        u[i]--; v[i]--;
    }
    ll ans=INF;
    vector<int> vec(m-n+1,0);
    rep(i,n-1) vec.push_back(1);
    do {
        UnionFind uf(n);
        bool flag=true;
        ll tot=0;
        rep(i,m) {
            if(vec[i]==0) continue;
            if(uf.same(u[i],v[i])) flag=true;
            uf.unite(u[i],v[i]);
            tot+=w[i];
            tot%=k;
        }
        if(uf.size(0)!=n) flag=false;
        if(flag) ans=min(ans,tot);
    } while(next_permutation(all(vec)));
    cout << ans << endl;
    return 0;
}