#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod=998244353;

ll perm(ll n,ll r) {
    r=n-r;
    ll res=1;
    for(int i=n;i>=r+1;i--) res=(res*i)%mod;
    return res;
} 

int main() {
    ll n;
    cin >> n;
    ll tot=0,tot1=perm((n-1)*(n-1),(n-1)*(n-1)),all=1;
    for(int i=1;i<=n*n;i++) all=(all*i)%mod;
    for(int i=n;i<=n*n-(n-1);i++) {
        ll res=1;
        res=(res*n*n)%mod;
        res=(res*perm(i-1,n-1))%mod;
        res=(res*perm(n*n-i,n-1))%mod;
        res=(res*tot1)%mod;
        tot=(tot+res)%mod;
    }
    cout << (all-tot+mod)%mod << endl;
    return 0;
}