#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,y;
    cin >> n >> y;
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            ll tot=i*10000+j*5000;
            if(y>=tot) {
                ll z=(y-tot)/1000;
                if(i+j+z==n) {
                    cout << i << " " << j << " " << z << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}