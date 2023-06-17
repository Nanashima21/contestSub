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
    vector<ll> a(3*n);
    rep(i,3*n) cin >> a[i];
    vector<ll> cnt(n),ans;
    rep(i,3*n) {
        cnt[a[i]-1]++;
        if(cnt[a[i]-1]==2) ans.push_back(a[i]);
    }
    rep(i,(int)ans.size()) {
        if(i) cout << " ";
        cout << ans[i];
    } cout << endl;
    return 0;
}