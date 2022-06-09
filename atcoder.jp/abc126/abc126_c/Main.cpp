#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,k;
    cin >> n >> k;
    double ans=1.0/n,tot=0.0;
    for(int i=1;i<=n;i++) {
        ll x=i;
        double y=1.0;
        while(x<k) {
            x*=2;
            y*=0.5;
        }
        tot+=y;
    }
    printf("%.16f\n",ans*tot);
    return 0;
}