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
    vector<ll> a(m),b(m);
    rep(i,m) cin >> a[i];
    rep(i,m) cin >> b[i];
    bool flag=true;
    rep(i,m) if(a[i]==b[i]) flag=false;
    vector<vector<int>> g(n,vector<int> ());
    rep(i,m) {
        g[a[i]-1].push_back(b[i]-1);
        g[b[i]-1].push_back(a[i]-1);
    }
    vector<ll> dist(n,INF);
    queue<pair<int,int>> q;
    rep(i,n) {
        if(dist[i]!=INF) continue;
        q.push({i,-1});
        dist[i]=0;
        while(!q.empty()) {
            int cv=q.front().first;
            int par=q.front().second;
            q.pop();
            for(auto nv:g[cv]) {
                if(par==nv) continue;
                if(dist[nv]!=INF) {
                    if((dist[nv]-dist[cv])%2==0) flag=false;
                    continue;
                } 
                dist[nv]=dist[cv]+1;
                q.push({nv,cv});
            }
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}