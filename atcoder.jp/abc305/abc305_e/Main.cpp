#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n,vector<int> ());
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<ll> dis(n,-1);
    priority_queue<pl,vector<pl>> pq;
    rep(i,k) {
        ll p,h;
        cin >> p >> h;
        p--;
        dis[p]=h;
        pq.push({h,p});
    }
    while(!pq.empty()) {
        ll ch=pq.top().first;
        int cv=pq.top().second;
        pq.pop();
        if(ch>dis[cv]) continue;
        for(auto nv:g[cv]) {
            if(ch-1>dis[nv]) {
                dis[nv]=ch-1;
                pq.push({dis[nv],nv});
            }
        }
    }
    vector<int> ans;
    rep(i,n) if(dis[i]>=0) ans.push_back(i+1);
    cout << (int)ans.size() << endl;
    rep(i,(int)ans.size()) {
        if(i) cout << " ";
        cout << ans[i];
    } cout << endl;  
    return 0;
}