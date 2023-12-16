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
    vector<int> t(n),x(n);
    rep(i,n) cin >> t[i] >> x[i];
    map<ll,ll> mp;
    vector<int> v;
    int ans=0,cap=0;
    for(int i=n-1;i>=0;i--) {
        if(t[i]==1) {
            if(mp[x[i]]>0) {
                mp[x[i]]--;
                v.push_back(1);
                cap--;
            } else v.push_back(0);
        } else {
            mp[x[i]]++;
            cap++;
        }
        ans=max(ans,cap);
    }
    for(auto u:mp) {
        if(u.second!=0) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    reverse(all(v));
    for(auto u:v) cout << u << " ";
    cout << endl; 
    return 0;
}