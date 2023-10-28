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
    ll ans=0;
    int r=0;
    sort(all(a));
    for(int l=0;l<n;l++) {
        while(r<n&&a[r]-a[l]<m) r++;
        ans=max(ans,(ll)r-l); 
        //cout << l << " " << r << endl;
    }
    cout << ans << endl;
    return 0;
}