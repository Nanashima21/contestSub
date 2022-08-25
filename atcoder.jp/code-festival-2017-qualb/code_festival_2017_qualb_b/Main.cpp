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
    cin >> n;
    vector<ll> d(n);
    map<ll,ll> mp;
    rep(i,n) {
        cin >> d[i];
        mp[d[i]]++;
    }
    cin >> m;
    vector<ll> t(m);
    bool flag=true;
    rep(i,m) {
        cin >> t[i];
        mp[t[i]]--;
        if(mp[t[i]]<0) flag=false;
    }
    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}