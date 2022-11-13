#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m,k;
    cin >> n >> m >> k;
    vector<vector<pair<int,int>>> g(n,vector<pair<int,int>> ());
    rep(i,m) {
        int u,v,a;
        cin >> u >> v >> a;
        u--; v--;
        g[u].push_back({v,a});
        g[v].push_back({u,a});
    } 
    vector<int> s(k);
    rep(i,k) {
        cin >> s[i];
        s[i]--;
    }
    deque<pair<int,int>> q;
    q.push_back({0,1});
    vector<ll> dis1(n,INF),dis0(n,INF);
    dis1[0]=0;
    while(!q.empty()) {
        int cv=q.front().first;
        int cur=q.front().second;
        q.pop_front();
        for(auto u:g[cv]) {
            if(cur==1) {
                if(u.second==1&&dis1[u.first]==INF) {
                    dis1[u.first]=dis1[cv]+1;
                    q.push_back({u.first,1});
                } else continue;
            } else {
                if(u.second==0&&dis0[u.first]==INF) {
                    dis0[u.first]=dis0[cv]+1;
                    q.push_back({u.first,0});
                } else continue;
            }
        }
        if(cur==1&&dis0[cv]==INF&&binary_search(all(s),cv)) {
            dis0[cv]=dis1[cv];
            q.push_front({cv,0});
        }
        if(cur==0&&dis1[cv]==INF&&binary_search(all(s),cv)) {
            dis1[cv]=dis0[cv];
            q.push_front({cv,1});
        }
    }
    if(dis1[n-1]==INF&&dis0[n-1]==INF) cout << -1 << endl;
    else cout << min(dis1[n-1],dis0[n-1]) << endl;
    return 0;
}