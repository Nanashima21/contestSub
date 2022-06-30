#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int h,w,k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    ll ans=0;
    for(int bit1=0;bit1<(1<<h);bit1++) {
        for(int bit2=0;bit2<(1<<w);bit2++) {
            vector<string> ns=s;
            rep(i,h) if(1<<i&bit1) {
                rep(j,w) ns[i][j]='.';
            }
            rep(i,w) if(1<<i&bit2) {
                rep(j,h) ns[j][i]='.';
            }
            int cnt=0;
            rep(i,h) rep(j,w) if(ns[i][j]=='#') cnt++;
            if(cnt==k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}