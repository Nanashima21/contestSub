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
    vector<int> a(n);
    vector<set<int>> s(n);
    vector<vector<int>> v(m,vector<int> ());
    rep(i,n) {
        cin >> a[i];
        rep(j,a[i]) {
            int x;
            cin >> x;
            x--;
            s[i].insert(x);
            v[x].push_back(i);
        }
    }
    priority_queue<pl,vector<pl>,greater<pl>> pq;
    vector<ll> dis(m,INF);
    rep(i,(int)v[0].size()) {
        for(auto u:s[v[0][i]]) {
            if(dis[u]==INF) {
                dis[u]=0;
                pq.push({0,u});
            }
        }
        set<int> se;
        swap(se,s[v[0][i]]);
    }
    while(!pq.empty()) {
        int cd=pq.top().first;
        int cv=pq.top().second;
        pq.pop();
        if(dis[cv]<cd) continue;
        rep(i,v[cv].size()) {
            for(auto u:s[v[cv][i]]) {
                if(dis[u]==INF) {
                    dis[u]=dis[cv]+1;
                    pq.push({dis[u],u});
                }
            }
            set<int> se;
            swap(se,s[v[cv][i]]);
        }
    }
    if(dis[m-1]==INF) dis[m-1]=-1;
    cout << dis[m-1] << endl;
    return 0;
}