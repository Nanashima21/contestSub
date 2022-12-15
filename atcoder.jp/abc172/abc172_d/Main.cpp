#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
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
    vector<ll> p(n+1);
    for(ll i=2;i<=n;i++) {
        for(ll j=i;j<=n;j+=i) p[j]++;
    }
    ll tot=0;
    for(ll i=0;i<=n;i++) tot+=(p[i]+1LL)*i;
    cout << tot << endl;
    return 0;
}