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
    vector<vector<pl>> g(n,vector<pl>());
    rep(i,m) {
        ll a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    ll ans=0;
    auto dfs = [&](auto dfs, int cv, ll cd, vector<bool> &flag) -> void {
        ans=max(ans,cd);
        for(auto u:g[cv]) {
            if(flag[u.first]) continue;
            flag[u.first]=true;
            dfs(dfs,u.first,cd+u.second,flag);
            flag[u.first]=false;
        }
    };
    rep(i,n) {
        vector<bool> flag(n,false);
        flag[i]=true;
        dfs(dfs,i,0,flag);
    }
    cout << ans << endl;
    return 0;
}