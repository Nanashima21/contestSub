#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,x,y;
    cin >> n >> x >> y;
    vector<vector<int>> g(n,vector<int> ());
    rep(i,n-1) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    } 
    queue<int> q;
    q.push(x-1);
    vector<ll> dist(n,INF);
    dist[x-1]=0;
    while(!q.empty()) {
        int cv=q.front();
        q.pop();
        for(auto u:g[cv]) {
            if(dist[u]!=INF) continue;
            dist[u]=dist[cv]+1;
            q.push(u);
        }
    }
    int dis=dist[y-1];
    vector<int> ans;
    ans.push_back(y);
    int idx=y-1;
    while(dist[idx]!=0) {
        for(auto u:g[idx]) {
            if(dist[idx]==dist[u]+1) {
                idx=u;
                ans.push_back(u+1);
            }
        }
    }
    reverse(all(ans));
    rep(i,(int)ans.size()) {
        if(i) cout << " ";
        cout << ans[i];
    } cout << endl;
    return 0;
}