#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<int>> v(2*n+2,vector<int> ());
    rep(i,n) {
        v[a[i]].push_back((i+1)*2);
        v[a[i]].push_back((i+1)*2+1);
    }
    queue<int> que;
    que.push(a[0]);
    vector<ll> dist(2*n+2,INF);
    dist[a[0]]=0;
    while(!que.empty()) {
        int cv=que.front();
        que.pop();
        for(auto u:v[cv]) {
            if(dist[u]!=INF) continue;
            dist[u]=dist[cv]+1;
            que.push(u);
        }
    }
    for(int i=1;i<=2*n+1;i++) cout << dist[i] << endl;
    return 0;
}