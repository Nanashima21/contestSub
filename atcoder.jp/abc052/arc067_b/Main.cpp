#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,a,b;
    cin >> n >> a >> b;
    vector<ll> x(n);
    rep(i,n) cin >> x[i];
    ll tot=0;
    for(int i=0;i<n-1;i++) tot+=min(a*(x[i+1]-x[i]),b);
    cout << tot << endl;
    return 0;
}