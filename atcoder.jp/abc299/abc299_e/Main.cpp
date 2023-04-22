#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m;
    cin >> n >> m;
    vector<vector<int>> g(n,vector<int> ());
    rep(i,m) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    } 
    ll k;
    cin >> k;
    vector<bool> white(n,false);
    vector<ll> p(k),d(k);
    vector<vector<ll>> dist(n,vector<ll> (n,INF));
    rep(i,k) {
        cin >> p[i] >> d[i];
        p[i]--;
        dist[p[i]][p[i]]=0;
        queue<int> q;
        q.push(p[i]);
        while(!q.empty()) {
            int cv=q.front();
            if(dist[p[i]][cv]<d[i]) white[cv]=true;
            q.pop();
            for(auto nv:g[cv]) {
                if(dist[p[i]][nv]!=INF) continue;
                dist[p[i]][nv]=dist[p[i]][cv]+1;
                q.push(nv);
            }
        }
    }
    vector<bool> isblack(n,false);
    rep(i,n) isblack[i]=!white[i];
    bool flag=false;
    rep(i,n) flag|=isblack[i];
    rep(i,k) {
        bool check=false;
        rep(j,n) if(dist[p[i]][j]==d[i]&&isblack[j]) check=true;
        if(!check) flag=false;
    }
    if(!flag) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        rep(i,n) cout << (isblack[i] ? 1:0);
        cout << endl;
    }
    return 0;
}