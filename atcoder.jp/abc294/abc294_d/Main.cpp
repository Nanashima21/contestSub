#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,q;
    cin >> n >> q;
    set<ll> se1,se2;
    rep(i,n) se2.insert(i+1);
    vector<ll> v;
    while(q--) {
        int t;
        cin >> t;
        if(t==1) {
            ll x=*se2.begin();
            se1.insert(x);
            se2.erase(x);
        } else if(t==2) {
            ll x;
            cin >> x;
            se1.erase(x);
        } else {
            v.push_back(*se1.begin());
        }
    }
    rep(i,(int)v.size()) cout << v[i] << endl;
    return 0;
}