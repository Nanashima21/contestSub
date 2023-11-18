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
    vector<ll> a(m);
    rep(i,m) cin >> a[i];
    vector<ll> cnt(n);
    set<pl> se;
    rep(i,n) se.insert({0,i});
    rep(i,m) {
        a[i]--;
        se.erase({cnt[a[i]],a[i]});
        cnt[a[i]]--;
        se.insert({cnt[a[i]],a[i]});
        cout << se.begin()->second+1 << '\n';
    }
    return 0;
}