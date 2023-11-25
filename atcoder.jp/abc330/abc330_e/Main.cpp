#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    set<ll> se;
    map<ll,ll> mp;
    rep(i,n+2) se.insert(i);
    rep(i,n) {
        if(mp[a[i]]==0) se.erase(a[i]);
        mp[a[i]]++;
    }

    rep(i,q) {
        int j; ll x;
        cin >> j >> x;
        j--;
        if(mp[x]==0) se.erase(x);
        mp[x]++;
        if(mp[a[j]]==1) se.insert(a[j]);
        mp[a[j]]--;
        a[j]=x;
    
        cout << *se.begin() << "\n";
    }
    return 0;
}