#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<int>> g(n,vector<int> ());
    vector<ll> deg(n);
    rep(i,m) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]+=a[v]; deg[v]+=a[u];
    }
    vector<bool> flag(n,false);
    ll ma=0;
    priority_queue<pl,vector<pl>> pq;
    rep(i,n) pq.push({-deg[i],i});
    while(!pq.empty()) {
        pl pp=pq.top();
        pq.pop();        
        if(flag[pp.second]) continue;
        flag[pp.second]=true;
        ma=max(ma,-pp.first);
        for(auto u:g[pp.second]) {
            if(flag[u]) continue;
            deg[u]-=a[pp.second];
            pq.push({-deg[u],u});
        }
    }
    cout << ma << endl;
    return 0;
}