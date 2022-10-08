#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

ll dis(ll x1,ll y1,ll x2,ll y2) {
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main() {
    ll n,m;
    cin >> n >> m;
    vector<ll> v;
    rep(i,m+1) v.push_back(i*i);
    vector<pl> p;
    for(ll i=0;i<=m;i++) {
        if(!binary_search(all(v),i)) continue;
        if(!binary_search(all(v),m-i)) continue;
        ll x=sqrt(i),y=sqrt(m-i);
        p.push_back({x,y});
        p.push_back({-x,y});
        p.push_back({x,-y});
        p.push_back({-x,-y});
    }
    vector<vector<int>> dist(n,vector<int> (n,-1));
    dist[0][0]=0;
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()) {
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        rep(i,(int)p.size()) {
            int nx=cx+p[i].first,ny=cy+p[i].second;
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(dist[nx][ny]!=-1) continue;
            dist[nx][ny]=dist[cx][cy]+1;
            q.push({nx,ny}); 
        }
    }
    rep(i,n) {
        rep(j,n) {
            if(j) cout << " ";
            cout << dist[i][j];
        }
        cout << endl;
    }
    return 0;
}