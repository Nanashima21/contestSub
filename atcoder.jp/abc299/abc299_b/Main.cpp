#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,t;
    cin >> n >> t;
    vector<ll> c(n),r(n);
    bool flag=false;
    rep(i,n) {
        cin >> c[i];
        if(t==c[i]) flag=true;
    }
    rep(i,n) cin >> r[i];
    int ans=0,ma=0;
    rep(i,n) {
        if(flag) {
            if(t==c[i]&&ma<r[i]) {
                ma=r[i];
                ans=i+1;
            }
        } else {
            if(c[0]==c[i]&&ma<r[i]) {
                ma=r[i];
                ans=i+1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}