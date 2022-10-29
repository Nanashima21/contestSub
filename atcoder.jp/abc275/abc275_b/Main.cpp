#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod=998244353;

int main() {
    vector<ll> v(6);
    rep(i,6) {
        cin >> v[i];
        v[i]%=mod;
    }
    ll t1=v[0];
    t1=(((t1*v[1])%mod)*v[2])%mod;
    ll t2=v[3];
    t2=(((t2*v[4])%mod)*v[5])%mod;
    cout << (t1-t2+mod)%mod << endl;
    return 0;
}