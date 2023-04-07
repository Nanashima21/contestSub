#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

class HLDecomposition {
private:
    void dfs_sz(int v) {
        auto &es = G[v];
        if(~par[v]) es.erase(find(all(es),par[v]));
        for(int &u:es) {
            dep[u] = dep[v] + 1;
            par[u] = v;
            dfs_sz(u);
            sub[v] += sub[u];
            if(sub[u] > sub[es[0]]) swap(u, es[0]);
        } 
    }
    void dfs_hld(int v, int &pos) {
        vid[v] = pos++;
        inv[vid[v]] = v;
        for(int u:G[v]) {
            if(u == par[v]) continue;
            nxt[u] = (u == G[v][0] ? nxt[v] : u);
            dfs_hld(u, pos);
        }
    }
public:
    vector<vector<int>> G;
    // vid: vertex -> idx
    // inv: idx -> vertex
    vector<int> vid, nxt, sub, par, inv, dep;

    HLDecomposition(int n) : G(n), vid(n, -1), nxt(n), sub(n, 1), par(n, -1), inv(n), dep(n) {}

    void add_edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }
    void build(int r = 0) {
        int pos = 0;
        dfs_sz(r); 
        nxt[r] = r;
        dfs_hld(r, pos);
    }
    int lca(int u, int v) {
        while(1) {
            if(vid[u] > vid[v]) swap(u, v);
            if(nxt[u] == nxt[v]) return u;
            v = par[nxt[v]];
        }
    }
    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    } 
    template<typename F>
    void for_each(int u, int v, const F& f) {
        while(1) {
            if(vid[u] > vid[v]) swap(u, v);
            f(max(vid[nxt[v]], vid[u]), vid[v]+1);
            if(nxt[u] != nxt[v]) v = par[nxt[v]];
            else break;
        }
    }
    template<typename F>
    void for_each_edge(int u, int v, const F& f) {
        while(1) {
            if(vid[u] > vid[v]) swap(u, v);
            if(nxt[u] != nxt[v]) {
                f(vid[nxt[v]], vid[v]+1);
                v = par[nxt[v]];
            } else {
                if(u != v) f(vid[u]+1, vid[v]+1);
                break;
            }
        }
    }
};

int main() {
    int n,u,v;
    cin >> n >> u >> v;
    u--; v--;
    HLDecomposition hld(n);
    rep(i,n-1) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        hld.add_edge(a,b);
    }
    hld.build(v);
    ll ans=0;
    rep(i,n) {
        // is_leaf?
        if(hld.G[i].size()!=0) continue; 
        ll lc=hld.lca(i,u);

        ll taka=hld.dist(lc,u); 
        ll aoki=hld.dist(lc,v);
        
        if(aoki<=taka) continue;

        ll taka2=hld.dist(i,u); 
        ll aoki2=hld.dist(i,v);

        ll cnt=taka2;
        ll d=aoki2-taka2;
        cnt+=d-1;
        ans=max(ans,cnt);
    }
    cout << ans << endl;
    return 0;
}