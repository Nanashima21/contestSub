#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod=998244353;

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

ll modpow(ll n,ll r,ll m) {
    ll num=1;
    n%=m;
    while(r) {
        if(r&1) num=num*n%m;
        n=n*n%m;
        r/=2;
    }
    return num;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n,vector<int> ());
    vector<int> lv(2*n),sz(2*n,1);
    rep(i,n) lv[i]=i;
    UnionFind uf(n);
    rep(i,n-1) {
        int p,q;
        cin >> p >> q;
        p--; q--;
        p=uf.find(p);
        q=uf.find(q);
        int par=(int)g.size();
        g.push_back(vector<int>{lv[p],lv[q]});
        uf.unite(p,q);
        lv[uf.find(p)]=par;
        sz[par]=uf.size(p);
    }
    // rep(i,(int)g.size()) {
    //     cout << i << ":";
    //     rep(j,(int)g[i].size()) cout << " " << g[i][j];
    //     cout << endl;
    // }
    int rt=(int)g.size()-1;
    vector<ll> dp(2*n);
    auto dfs = [&](auto dfs, int cv) -> void {
        // cout << cv << " " << sz[cv] << endl;
        for(auto nv:g[cv]) {
            dp[nv]=(dp[cv]+sz[nv]*modpow(sz[cv],mod-2,mod)%mod)%mod;
            dfs(dfs,nv);
        }
    };
    dfs(dfs,rt);
    rep(i,n) {
        if(i) cout << " ";
        cout << dp[i];
    } cout << endl;
    return 0;
}