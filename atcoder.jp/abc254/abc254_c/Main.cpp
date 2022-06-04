#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n),b(n);
    rep(i,n) {
        cin >> a[i];
        b[i]=a[i];
    }
    sort(all(b));
    vector<vector<ll>> v(k,vector<ll> ());
    rep(i,k) {
        for(int j=i;j<n;j+=k) v[i].push_back(a[j]);
        sort(all(v[i]));
        int idx=0;
        for(int j=i;j<n;j+=k) a[j]=v[i][idx++];
    }
    cout << ((a==b) ? "Yes" : "No") << endl;
    return 0;
}