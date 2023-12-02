#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,s,m,l;
    cin >> n >> s >> m >> l;
    ll ans=INF;
    for(ll i=0;i<=100;i++) {
        for(ll j=0;j<=100;j++) {
            for(ll k=0;k<=100;k++) {
                if(i*6+j*8+k*12>=n) {
                    ans=min(ans,i*s+j*m+k*l);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}