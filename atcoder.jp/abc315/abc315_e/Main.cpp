#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    vector<ll> c(n);
    vector<vector<ll>> g(n,vector<ll>());
    rep(i,n) {
        cin >> c[i];
        rep(j,c[i]) {
            ll p;
            cin >> p;
            p--;
            g[i].push_back(p);
        }
    }
    rep(i,n) sort(all(g[i]));

    vector<bool> flag(n,false);
    vector<int> ans;

    auto dfs = [&](auto dfs, int cv) -> void {
        for(auto nv:g[cv]) {
            if(flag[nv]) continue;
            flag[nv]=true;
            dfs(dfs,nv);
        }
        ans.push_back(cv);
    };

    flag[0]=true;
    dfs(dfs, 0);
    rep(i,(int)ans.size()-1) {
        if(i) cout << " ";
        cout << ans[i]+1;
    } cout << endl;
    return 0;
}