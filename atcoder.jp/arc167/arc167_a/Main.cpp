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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(rall(a));
    ll ans=0;
    rep(i,2*m-n) ans+=a[i]*a[i];
    vector<ll> b;
    for(int i=2*m-n;i<n;i++) b.push_back(a[i]);
    int x=(int)b.size();
    rep(i,x/2) ans+=(b[i]+b[x-i-1])*(b[i]+b[x-i-1]); 
    cout << ans << endl;
    return 0;
}