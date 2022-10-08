#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> x,y;
    rep(i,n) {
        if(a[i]%2==0) x.push_back(a[i]);
        else y.push_back(a[i]);
    }
    int xx=(int)x.size(),yy=(int)y.size();
    sort(all(x)); sort(all(y));
    if(xx>=2||yy>=2) {
        if(xx<=1) cout << y[yy-1]+y[yy-2] << endl;
        else if(yy<=1) cout << x[xx-1]+x[xx-2] << endl;
        else cout << max(x[xx-1]+x[xx-2],y[yy-1]+y[yy-2]) << endl;
    } else cout << -1 << endl;
    return 0;
}