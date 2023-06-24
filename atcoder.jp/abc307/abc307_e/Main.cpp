#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod=998244353;

int main() {
    ll n,m;
    cin >> n >> m;
    if(n==2) {
        cout << m*(m-1)%mod << endl;
        return 0;
    }
    vector<ll> v(n),u(n);
    v[0]=m%mod,v[1]=m*(m-1)%mod;
    for(int i=2;i<n;i++) {
        v[i]=v[i-1]*(m-1)%mod;
        u[i]=(v[i-1]-u[i-1]+mod)%mod;
    }
    ll x=(v[n-2]-u[n-2]+mod)%mod*((m-2+mod)%mod)%mod;
    ll y=(m-1+mod)%mod*u[n-2]%mod;
    ll ans=(x+y)%mod;
    ans+=mod;
    ans%=mod;
    cout << ans << endl;
    return 0;
}