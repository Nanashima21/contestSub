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
ll ans=1;

void dfs(int pos) {
    flag[pos]=true;
    for(auto nv:g[pos]) {
        if(flag[nv]||ans>=1e6) continue;
        dfs(nv);
        ans++;
    }
    flag[pos]=false;
    if(ans>=1e6) return;
}

int main() {
    int n,m;
    cin >> n >> m;
    g.resize(n,vector<int> ());
    rep(i,m) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    flag.assign(n,false);
    flag[0]=true;
    for(auto u:g[0]) {
        ans++;
        dfs(u);
    }
    cout << min(ans,(ll)1e6) << endl;
    return 0;
}