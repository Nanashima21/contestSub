#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n; string s,t;
    cin >> n >> s >> t;
    string ns=s,nt=t;
    sort(all(ns));
    sort(all(nt));
    if(ns!=nt) cout << -1 << endl;
    else if(s==t) cout << 0 << endl;
    else {
        vector<vector<ll>> v(26,vector<ll> ());
        rep(i,n) v[t[n-i-1]-'a'].push_back(i);
        ll ans=INF,pre=0;
        rep(i,n) {
            auto x=lower_bound(all(v[s[n-i-1]-'a']),pre);
            if(x==v[s[n-i-1]-'a'].end()) break;
            ans=min(ans,n-i-1);
            pre=*x+1;
        }
        cout << ans << endl;
    }
    return 0;
}