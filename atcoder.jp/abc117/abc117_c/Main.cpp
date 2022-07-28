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
    vector<ll> x(m),y;
    rep(i,m) cin >> x[i];
    sort(all(x));
    rep(i,m-1) y.push_back(abs(x[i]-x[i+1]));
    sort(all(y));
    ll tot=0;
    rep(i,m-n) tot+=y[i];
    cout << tot << endl;
    return 0;
}