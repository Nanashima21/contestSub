#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod=1000000007;

int main() {
    int n,a,b,m;
    cin >> n >> a >> b >> m;
    a--; b--;
    vector<vector<int>> g(n,vector<int> ());
    rep(i,m) {
        int x,y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    queue<int> q;
    q.push(a);
    vector<ll> dist(n,INF);
    dist[a]=0;
    while(!q.empty()) {
        int cv=q.front();
        q.pop();
        for(auto nv:g[cv]) {
            if(dist[nv]!=INF) continue;
            dist[nv]=dist[cv]+1;
            q.push(nv);
        }
    }
    vector<ll> tot(n,0);
    vector<bool> flag(n,false);
    tot[b]=1;
    flag[b]=true;
    q.push(b);
    while(!q.empty()) {
        int cv=q.front();
        q.pop();
        for(auto nv:g[cv]) {
            if(dist[cv]+1==dist[nv]) {
                tot[cv]+=tot[nv];
                tot[cv]%=mod;
            }
            if(flag[nv]) continue;
            flag[nv]=true;
            q.push(nv);
        }
    }
    cout << tot[a] << endl;
    return 0;
}