#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    vector<vector<int>> g(n, vector<int> ());
    rep(i,n-1) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> flag(n,false);
    vector<int> cnt(n,0);
    auto dfs = [&](auto dfs, int cv) -> void {
        for(auto nv:g[cv]) {
            if(flag[nv]) continue;
            flag[nv]=true;
            dfs(dfs,nv);
            cnt[cv]+=cnt[nv];
        }
        cnt[cv]++;
    };
    flag[0]=true;
    dfs(dfs,0);
    ll tot=0;
    vector<ll> v;
    for(auto nv:g[0]) {
        v.push_back(cnt[nv]);
        // cout << nv << " " << cnt[nv] << endl;
    }
    sort(rall(v));
    cout << cnt[0]-v[0] << endl;
    return 0;
}