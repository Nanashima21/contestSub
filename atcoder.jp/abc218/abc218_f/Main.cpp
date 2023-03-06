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
    vector<int> u(m),v(m);
    vector<vector<int>> g(n,vector<int> ());
    vector<vector<int>> rg(n,vector<int> ());
    map<pair<int,int>,int> mp;
    rep(i,m) {
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        g[u[i]].push_back(v[i]);
        rg[v[i]].push_back(u[i]);
        mp[{u[i],v[i]}]=i;
    }
    queue<int> q;
    q.push(0);
    vector<ll> dist(n,INF);
    dist[0]=0;
    while(!q.empty()) {
        int cv=q.front();
        q.pop();
        for(auto nv:g[cv]) {
            if(dist[nv]!=INF) continue;
            dist[nv]=dist[cv]+1;
            q.push(nv);
        }
    }
    if(dist[n-1]==INF) rep(i,m) cout << -1 << endl;
    else {
        vector<bool> flag(m,false);
        int cur=n-1;
        while(cur!=0) {
            for(auto pv:rg[cur]) {
                if(dist[pv]+1!=dist[cur]) continue; 
                flag[mp[{pv,cur}]]=true;
                cur=pv;
            }
        }
        rep(i,m) {
            if(!flag[i]) cout << dist[n-1] << endl;
            else {
                q.push(0);
                vector<ll> dis(n,INF);
                dis[0]=0;
                while(!q.empty()) {
                    int cv=q.front();
                    q.pop();
                    for(auto nv:g[cv]) {
                        if(cv==u[i]&&nv==v[i]) continue;
                        if(dis[nv]!=INF) continue;
                        dis[nv]=dis[cv]+1;
                        q.push(nv);
                    }
                }
                if(dis[n-1]==INF) dis[n-1]=-1;
                cout << dis[n-1] << endl;
            }
        }
    }
    return 0;
}