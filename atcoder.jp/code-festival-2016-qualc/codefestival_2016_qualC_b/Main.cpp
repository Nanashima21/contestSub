#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll k,t;
    cin >> k >> t;
    vector<ll> a(t);
    rep(i,t) cin >> a[i];
    sort(rall(a));
    ll ma=a[0],tot=k-a[0];
    if(ma<=tot) cout << 0 << endl;
    else cout << ma-tot-1 << endl;
    return 0;
}