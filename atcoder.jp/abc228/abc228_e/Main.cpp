#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod=998244353;

ll modpow(ll n,ll r,ll m) {
    ll num=1;
    n%=m;
    while(r) {
        if(r&1) num=num*n%m;
        n=n*n%m;
        r/=2;
    }
    return num;
}

int main() {
    ll n,k,m;
    cin >> n >> k >> m;
    if(m%mod==0) cout << 0 << endl;
    else cout << modpow(m,modpow(k,n,mod-1),mod) << endl;
    return 0;
}