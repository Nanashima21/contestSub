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
    vector<vector<int>> g(n,vector<int> ());
    rep(i,m) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }
    int s,t;
    cin >> s >> t;
    s--; t--; 
    queue<pair<int,int>> q;
    q.push({s,0});
    vector<vector<ll>> dist(n,vector<ll> (3,INF));
    dist[s][0]=0;
    while(!q.empty()) {
        int cv=q.front().first;
        int cs=q.front().second;
        q.pop();
        for(auto nv:g[cv]) {
            if(dist[nv][(cs+1)%3]!=INF) continue;
            dist[nv][(cs+1)%3]=dist[cv][cs]+1;
            q.push({nv,(cs+1)%3});
        }
    }
    if(dist[t][0]==INF) dist[t][0]=-3;
    std::cout << dist[t][0]/3 << endl;
    return 0;
}