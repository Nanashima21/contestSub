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
    set<ll> se;
    rep(i,n) {
        ll a;
        cin >> a;
        se.insert(a);
    }
    vector<ll> v;
    for(auto u:se) v.push_back(u);
    cout << v[(int)v.size()-2] << endl; 
    return 0;
}