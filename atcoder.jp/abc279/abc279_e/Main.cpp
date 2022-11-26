#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m;
    cin >> n >> m;
    vector<ll> a(m);
    rep(i,m) cin >> a[i];
    vector<set<int>> se(n+1);
    rep(i,m) se[1].insert(i);
    rep(i,m) {
        swap(se[a[i]],se[a[i]+1]);
        if(se[a[i]].find(i)!=se[a[i]].end()) {
            se[a[i]].erase(i);
            se[a[i]+1].insert(i);
        } else if(se[a[i]+1].find(i)!=se[a[i]+1].end()) {
            se[a[i]].insert(i);
            se[a[i]+1].erase(i);
        }
    }
    vector<int> ans(m);
    rep(i,n) for(auto u:se[i+1]) ans[u]=i+1;
    rep(i,m) cout << ans[i] << endl;
    return 0;
}