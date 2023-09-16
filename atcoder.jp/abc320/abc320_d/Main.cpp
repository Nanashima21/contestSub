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
    vector<vector<pair<ll,pl>>> p(n,vector<pair<ll,pl>>());
    rep(i,m) {
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        a--; b--;
        p[a].push_back({b,{c,d}});
        p[b].push_back({a,{-c,-d}});
    }
    queue<int> q;
    q.push(0);
    vector<pl> v(n,{INF,INF});
    v[0]={0,0};
    while(!q.empty()) {
        int cv=q.front();
        q.pop();
        for(auto u:p[cv]) {
            int nv=u.first;
            if(v[nv].first!=INF||v[nv].second!=INF) continue;
            v[nv]={v[cv].first+u.second.first,v[cv].second+u.second.second};
            q.push(nv);
        }
    }
    rep(i,n) {
        if(v[i].first==INF) cout << "undecidable" << endl; 
        else cout << v[i].first << " " << v[i].second << endl;
    }
    return 0;
}