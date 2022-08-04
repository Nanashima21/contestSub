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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    set<ll> se;
    rep(i,n+10) se.insert(i);
    map<ll,int> mp;
    rep(i,m) {
        mp[a[i]]++;
        if(mp[a[i]]==1) se.erase(a[i]);
    }
    ll mi=*se.begin();
    for(int i=m;i<n;i++) {
        mp[a[i-m]]--;
        if(mp[a[i-m]]==0) se.insert(a[i-m]);
        mp[a[i]]++;
        if(mp[a[i]]==1) se.erase(a[i]);
        mi=min(mi,*se.begin());
    }
    cout << mi << endl;
    return 0;
}