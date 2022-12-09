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
    vector<vector<pl>> g(n,vector<pl> ());
    rep(i,m) {
        int a,b; ll c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back({b,c});
    }
    rep(i,n) {
        vector<ll> dist(n,INF);
        dist[i]=0;
        vector<bool> flag(n,false); 
        flag[i]=true;
        priority_queue<pl,vector<pl>,greater<pl>> pq;
        pq.push({0,i});
        ll mi=INF;
        while(!pq.empty()) {
            ll cd=pq.top().first;
            int cv=pq.top().second;
            pq.pop();
            if(dist[cv]<cd) continue;
            for(auto u:g[cv]) {
                ll nd=cd+u.second;
                int nv=u.first;
                if(nv==i) mi=min(mi,nd);
                if(nd>dist[nv]) continue;
                dist[nv]=nd;
                pq.push({dist[nv],nv});
            }
        }
        if(mi==INF) mi=-1;
        cout << mi << endl;
    }
    return 0;
}