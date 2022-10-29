#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

set<ll> se;
map<ll,ll> mp; 

ll f(ll k) {
    if(se.find(k)!=se.end()) return mp[k];
    else {
        ll tot=f(k/2)+f(k/3);
        se.insert(k);
        mp[k]=tot;
        return  tot;
    }
}

int main() {
    ll n;
    cin >> n;
    se.insert(0);
    mp[0]=1;
    cout << f(n) << endl;
    return 0;
}