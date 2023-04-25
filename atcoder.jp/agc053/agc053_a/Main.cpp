#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n; string s;
    cin >> n >> s;
    vector<ll> a(n+1);
    rep(i,n+1) cin >> a[i];
    ll k=INF;
    rep(i,n) k=min(k,abs(a[i]-a[i+1]));
    vector<vector<ll>> v(k,vector<ll> (n+1));
    rep(i,n+1) {
        rep(j,a[i]%k) v[j][i]++;
        ll x=a[i]/k;
        for(int j=0;j<k;j++) {
            if(a[i]>=x) v[j][i]+=x;
            else v[j][i]+=a[i];
            a[i]-=x;
        }
    }
    cout << k << endl;
    rep(i,k) {
        rep(j,n+1) {
            if(j) cout << " ";
            cout << v[i][j];
        } cout << endl;
    }
    return 0;
}