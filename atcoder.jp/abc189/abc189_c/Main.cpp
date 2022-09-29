#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >>  n;
    vector<ll> a(n);
    set<ll> se;
    rep(i,n) {
        cin >> a[i];
        se.insert(a[i]);
    }
    vector<ll> v;
    for(auto u:se) v.push_back(u);
    ll ma=0;
    for(auto u:v) {
        int cnt=0; 
        rep(i,n) {
            if(a[i]>=u) cnt++;
            else {
                ma=max(ma,u*cnt);
                cnt=0;
            }
        }
        ma=max(ma,u*cnt);
    }
    cout << ma << endl;
    return 0;
}