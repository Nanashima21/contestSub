#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

bool isprime(ll x) {
    if(x<2) return 0;
    else if(x==2) return 1;
    if(x%2==0) return 0;
    for(ll i=3;i*i<=x;i+=2) if(x%i==0) return 0;
    return 1;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> p;
    for(ll i=2;i<=1e6;i++) if(isprime(i)) p.push_back(i);
    ll ans=0;
    for(int i=0;i<(int)p.size();i++) {
        if(p[i]*p[i]>=n) break;
        for(int j=i+1;j<(int)p.size();j++) {
            ll m=n;
            m/=(p[i]*p[i]);
            m/=(p[j]*p[j]);
            if(m==0) break;
            ll it=lower_bound(all(p),m)-p.begin();
            if(p[i]*p[i]*p[j]*p[j]*p[it]>n) it--;
            if(i>=it) break;
            if(j<=it) it=j-1;
            ans+=it-i;
        }
    }
    cout << ans << endl;
    return 0;
}