#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,q;
    cin >> n >> q;
    vector<vector<int>> g(n,vector<int> ());
    rep(i,n-1) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int> que;
    que.push(0);
    vector<ll> dist(n,INF);
    dist[0]=0;
    while(!que.empty()) {
        int cv=que.front();
        que.pop();
        for(auto u:g[cv]) {
            if(dist[u]!=INF) continue;
            dist[u]=dist[cv]+1;
            que.push(u);
        }
    }
    rep(i,q) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        cout << (dist[u]%2==dist[v]%2 ? "Town" : "Road") << endl;
    }
    return 0;
}