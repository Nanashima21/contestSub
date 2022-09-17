#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    int l=1,r=n,u=1,d=n;
    int in;
    while(true) {
        int midx=(l+r)/2;
        cout << "? " << l << " " << midx << " " << 1 << " " << n << endl;
        cin >> in;
        int mi=midx-l+1;
        if(mi==in) l=midx+1;
        else r=midx;
        if(l==r) break;
    }
    while(true) {
        int midy=(u+d)/2;
        cout << "? " << 1 << " " << n << " " << u << " " << midy << endl;
        cin >> in;
        int mi=midy-u+1;
        if(mi==in) u=midy+1;
        else d=midy;
        if(u==d) break;
    }
    cout << "! " << l << " " << d << endl;
    return 0;
}