#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

template<typename T>
vector<T> dijkstra(vector<vector<pl>> &g,int s) {
    vector<T> dist(g.size(),INF);
    using Pi=pair<T,int>;
    priority_queue<Pi,vector<Pi>,greater<Pi>> que;
    dist[s]=0;
    que.emplace(dist[s],s);
    while(!que.empty()) {
        T cost; int idx;
        tie(cost,idx)=que.top(); que.pop();
        if(dist[idx]<cost) continue;
        for(auto &e:g[idx]) {
            auto next_cost=cost+e.second;
            if(dist[e.first]<=next_cost) continue;
            dist[e.first]=next_cost;
            que.emplace(dist[e.first],e.first);
        }
    }
    return dist;
    //vector<ll> dist=dijkstra<ll>(g,s);
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<pl>> g(n,vector<pl> ());
    int s,t;
    cin >> s >> t;
    s--; t--;
    rep(i,m) {
        int x,y; ll d;
        cin >> x >> y >> d;
        x--; y--;
        g[x].push_back({y,d});
        g[y].push_back({x,d});
    }
    vector<ll> dists=dijkstra<ll>(g,s);
    vector<ll> distt=dijkstra<ll>(g,t);
    int ans=-1;
    rep(i,n) if(dists[i]==distt[i]&&dists[i]!=INF) ans=i+1;
    cout << ans << endl;
    return 0;
}