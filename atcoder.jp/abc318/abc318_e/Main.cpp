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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<ll>> v(n+1,vector<ll> ());
    rep(i,n) v[a[i]].push_back(i);
    ll ans=0;
    rep(i,n+1) {
        if((int)v[i].size()<=1) continue;
        for(int j=1;j<(int)v[i].size();j++) {
            ll l=j,r=(ll)v[i].size()-l;
            //cout << l << " " << r << " " << v[i][j]-v[i][j-1]-1 << endl;
            ans+=l*r*(v[i][j]-v[i][j-1]-1);
        }
    }
    cout << ans << endl;
    return 0;
}