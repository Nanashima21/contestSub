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
    vector<ll> a(n),b(m),v;
    rep(i,n) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    rep(i,m) {
        cin >> b[i];
        v.push_back(b[i]);
    }
    sort(all(v));
    rep(i,n) {
        if(i) cout << " ";
        cout << lower_bound(all(v),a[i])-v.begin()+1;
    } cout << endl;
    rep(i,m) {
        if(i) cout << " ";
        cout << lower_bound(all(v),b[i])-v.begin()+1;
    } cout << endl;
    return 0;
}