#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod=998244353;

class TwelvefoldWay {
public:
    vector<ll> fact, infact;
    TwelvefoldWay(ll n) : fact(n+1, 1), infact(n+1, 1) {
        assert(n <= 1e9);
        for(ll i=1;i<=n;i++) fact[i] = i * fact[i-1] % mod;
        infact[n] = modpow(fact[n], mod-2);
        for(ll i=n-1;i>0;i--) infact[i] = infact[i+1] * (i+1) %mod;
    }
    ll perm(ll n, ll k) {
        assert(n >= k);
        return fact[n] % mod * infact[n-k] % mod;
    }
    ll comb(ll n, ll k) {
        assert(n >= k);
        return fact[n] * infact[k] % mod * infact[n-k] % mod;
    }
    ll modpow(ll n,ll r) {
        ll ret = 1;
        while(r) {
            if(r & 1) ret = ret * n % mod;
            n = n * n % mod;
            r /= 2;
        }
        return ret;
    }
    ll modinv(ll x) {
        return modpow(x, mod-2);
    } 
    // 1. n個の玉を区別, x個の箱を区別, 配り方に制限なし
    ll bab1(ll n, ll x) {
        return modpow(x, n);
    }
    // 2. n個の玉を区別, x個の箱を区別, 箱には1個以内(単射)
    ll bab2(ll n, ll x) {
        if(n > x) { return 0; } else { return perm(x, n); }
    }
    // 3. n個の玉を区別, x個の箱を区別, 箱には1個以上(全射) O(xlogn)
    ll bab3(ll n, ll x) {
        ll ret = 0;
        for(ll i=0;i<=x;i++) {
            if((x-i) % 2 == 0) {
                ret += comb(x, i) * modpow(i, n) % mod;
            } else {
                ret += mod - comb(x, i) * modpow(i, n) % mod;
            }
            ret %= mod;
        }
        return ret;
    }
    // 4. n個の玉を区別しない, x個の箱を区別, 配り方に制限なし
    ll bab4(ll n, ll x) {
        return comb(n+x-1, n);
    }
    // 5. n個の玉を区別しない, x個の箱を区別, 箱には1個以内(単射)
    ll bab5(ll n, ll x) {
        if(n > x) { return 0; } else { return comb(x, n); }
    }
    // 6. n個の玉を区別しない, x個の箱を区別, 箱には1個以上(全射)
    ll bab6(ll n, ll x) {
        if(n < x) { return 0; } else { return comb(n-1, n-x); }
    }
    // 7. n個の玉を区別, x個の箱を区別しない, 配り方に制限なし O(x^2logn)
    ll bab7(ll n, ll x) {
        ll ret = 0; 
        for(ll i=0;i<=x;i++) {
            ret += bab3(n, i) * infact[i] % mod;
            ret %= mod;
        }
        return ret;
    }
    // 8. n個の玉を区別, x個の箱を区別しない, 箱には1個以内(単射)
    ll bab8(ll n, ll x) {
        return (n <= x);
    }
    // 9. n個の玉を区別, x個の箱を区別しない, 箱には1個以上(全射)
    ll bab9(ll n, ll x) {
        return bab3(n, x) * infact[x] % mod;
    }
    // 10. n個の玉を区別しない, x個の箱を区別しない, 配り方に制限なし O(nx)
    ll bab10(ll n, ll x) {
        vector<vector<ll>> dp(n+1, vector<ll> (x+1));
        dp[0][0] = 1;
        for(int i=0;i<=n;i++) {
            for(int j=1;j<=x;j++) {
                if(i - j >= 0) {
                    dp[i][j] = (dp[i][j-1] + dp[i-j][j]) % mod;
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[n][x];
    }
    // 11. n個の玉を区別しない, x個の箱を区別しない, 箱には1個以内(単射)
    ll bab11(ll n, ll x) {
        return bab8(n, x);
    }
    // 12. n個の玉を区別しない, x個の箱を区別しない, 箱には1個以上(全射)
    ll bab12(ll n, ll x) {
        if(n < x) { return 0; } else { return bab10(n-x, x); }
    }
};

int main() {
    ll n,m;
    cin >> n >> m;
    TwelvefoldWay tw(2*(n+m));
    vector<ll> div(m+1,-1);
    for(int i=2;i<=m;i++) {
        if(div[i]!=-1) continue;
        for(int j=i;j<=m;j+=i) div[j]=i;
    }
    ll ans=0;
    for(int i=1;i<=m;i++) {
        ll num=1,val=i;
        map<ll,ll> mp;
        while(val!=1) {
            mp[div[val]]++;
            val/=div[val];
        }
        for(auto u:mp) {
            num*=tw.bab4(u.second,n);
            num%=mod;
        }
        ans+=num;
        ans%=mod;
    }
    cout << ans << endl;
    return 0;
}