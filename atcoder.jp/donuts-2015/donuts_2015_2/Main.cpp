#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(m);
    rep(i,n) cin >> a[i];
    vector<vector<int>> v(m,vector<int> ());
    rep(i,m) {
        int c;
        cin >> b[i] >> c;
        rep(j,c) {
            int k;
            cin >> k;
            k--;
            v[i].push_back(k);
        }
    }
    ll ans=0;
    for(int bit=0;bit<(1<<n);bit++) {
        if(__builtin_popcount(bit)!=9) continue;
        vector<int> flag(n,false);
        ll tot=0;
        rep(i,n) if(bit>>i&1) {
            flag[i]=true;
            tot+=a[i];
        }
        rep(i,m) {
            int cnt=0; 
            rep(j,(int)v[i].size()) if(flag[v[i][j]]) cnt++;
            if(cnt>=3) tot+=b[i];
        }
        ans=max(ans,tot);
    }
    cout << ans << endl;
    return 0;
}