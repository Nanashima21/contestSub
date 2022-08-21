#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m,t;
    cin >> n >> m >> t;
    vector<ll> a(n);
    for(int i=1;i<n;i++) cin >> a[i];
    map<ll,ll> mp;
    rep(i,m) {
        ll x,y;
        cin >> x >> y;
        x--; 
        mp[x]=y;
    }
    bool flag=true;
    for(int i=1;i<n;i++) {
        t-=a[i];
        if(t<=0) flag=false;
        t+=mp[i];
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}