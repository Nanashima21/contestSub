#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m,s;
    cin >> n >> m >> s;
    s=min(s,3000LL);
    vector<ll> a(m),b(m),c(n),d(n);
    vector<vector<pl>> g(n,vector<pl> ());
    rep(i,m) {
        int u,v;
        cin >> u >> v >> a[i] >> b[i];
        u--; v--;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    rep(i,n) cin >> c[i] >> d[i];
    vector<vector<ll>> cost(n,vector<ll> (3030,INF));
    vector<vector<bool>> flag(n,vector<bool> (3030,false));
    vector<ll> ans(n,INF);
    cost[0][s]=0;
    priority_queue<pl,vector<pl>,greater<pl>> pq;
    pq.push({0,s});
    while(!pq.empty()) {
        pl p=pq.top();
        pq.pop();
        ll cc=p.first;
        ll cv=p.second/3030,cs=p.second%3030;
        if(flag[cv][cs]) continue;
        flag[cv][cs]=true;
        ans[cv]=min(ans[cv],cc);
        for(auto u:g[cv]) {
            ll nv=u.first;
            ll idx=u.second;
            if(cs<a[idx]) continue;
            ll nc=cc+b[idx];
            if(cost[nv][cs-a[idx]]>nc) {
                cost[nv][cs-a[idx]]=nc;
                pq.push({nc,nv*3030+(cs-a[idx])});
            }
        }
        ll nc=cc+d[cv];
        ll ns=min(cs+c[cv],3000LL);
        if(cost[cv][ns]>nc) {
            cost[cv][ns]=nc;
            pq.push({nc,cv*3030+ns});
        }
    }
    for(int i=1;i<n;i++) cout << ans[i] << endl;
    return 0;
}