#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod=1000000007;

int main() {
    ll n,m;
    cin >> n >> m;
    ll tot=1;
    if(abs(n-m)>=2) tot=0;
    for(ll i=1;i<=n;i++) tot=(tot*i)%mod;
    for(ll i=1;i<=m;i++) tot=(tot*i)%mod;
    if(n==m) tot=(tot*2)%mod;
    cout << tot << endl;
    return 0;
}