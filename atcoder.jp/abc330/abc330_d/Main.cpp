#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<int> r(n),l(n);
    rep(i,n) {
        int cntr=0,cntl=0;
        rep(j,n) if(s[i][j]=='o') cntr++;
        rep(j,n) if(s[j][i]=='o') cntl++;
        r[i]=cntr; l[i]=cntl;
    }
    ll ans=0;

    rep(i,n) rep(j,n) {
        if(s[i][j]=='o'&&r[i]>=2&&l[j]>=2) ans+=(r[i]-1)*(l[j]-1);
    }
    cout << ans << endl;
    return 0;
}