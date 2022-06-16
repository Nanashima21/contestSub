#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod=1000000007;

ll modpow(ll n,ll r) {
    ll num=1;
    while(r) {
        if(r&1) num=num*n%mod;
        n=n*n%mod;
        r/=2;
    }
    return num;
}

int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n),cnt(n);
    rep(i,n) cin >> a[i];
    ll tot=0;
    rep(i,n) for(int j=i+1;j<n;j++) if(a[i]>a[j]) {
        cnt[j]++;
        tot++;
    }
    if(k==1) cout << tot << endl;
    else {
        vector<ll> cnt2(n);
        reverse(all(a));
        rep(i,n) for(int j=i+1;j<n;j++) if(a[i]>a[j]) cnt2[i]++;
        ll tot1=0,tot2=0;
        rep(i,n) {
            tot1+=(((k*(k+1))/2)%mod)*cnt[i]%mod;
            tot1%=mod;  
        } 
        rep(i,n) {
            tot2+=(((k*(k-1))/2)%mod)*cnt2[i]%mod;
            tot2%=mod;  
        } 
        cout << (tot1+tot2)%mod << endl;
    }
    return 0;
}