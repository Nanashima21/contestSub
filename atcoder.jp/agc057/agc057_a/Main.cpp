#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

ll f(ll x,ll r) {
    if(x>1e17) return r+1;
    string str="1"+to_string(x);
    return min(x*10,stoll(str));
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll l,r;
        cin >> l >> r;
        ll ng=l-1,ok=r;
        while(ok-ng>1) {
            ll mid=(ok+ng)/2;
            if(f(mid,r)<=r) ng=mid;
            else ok=mid;
        }
        cout << r-ok+1 << "\n";
    }
    return 0;
}