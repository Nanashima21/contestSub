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
    ll q;
    cin >> q;
    ll ans=1;
    queue<ll> que;
    que.push(1);
    while(q--) {
        int t;
        cin >> t;
        if(t==1) {
            ll x;
            cin >> x;
            ans=(ans*10%mod+x)%mod;
            que.push(x);
        } else if(t==2) {
            ll x=(ll)que.size();
            ans=(ans-(que.front()*modpow(10,x-1,mod))%mod+mod)%mod;
            que.pop();
        } else {
            cout << ans << '\n';
        }
    }
    return 0;
}