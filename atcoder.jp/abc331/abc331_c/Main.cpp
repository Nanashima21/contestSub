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
    map<ll,ll> mp;
    rep(i,n) {
        cin >> a[i];
        mp[a[i]]++;
    }
    ll tot=0;
    vector<ll> rtot;
    vector<ll> val;
    for(auto u:mp) {
        tot+=u.first*u.second;
        rtot.push_back(u.first*u.second);
        val.push_back(u.first);
    }
    rep(i,(int)rtot.size()-1) rtot[i+1]+=rtot[i];
    rep(i,n) {
        int it=lower_bound(all(val),a[i])-val.begin();
        cout << tot-rtot[it] << " ";
    } cout << endl;
    return 0;
}