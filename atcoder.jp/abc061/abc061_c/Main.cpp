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
    map<ll,ll> mp;
    rep(i,n) {
        ll a,b;
        cin >> a >> b;
        mp[a]+=b;
    }
    vector<pl> p;
    for(auto u:mp) p.push_back(u);
    int idx=0;
    while(k>0) {
        if(k-p[idx].second<=0) {
            cout << p[idx].first << endl;
            return 0;
        } else k-=p[idx].second;
        idx++;
    }
    return 0;
}