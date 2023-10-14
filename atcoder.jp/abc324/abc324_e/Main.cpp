#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n; string t;
    cin >> n >> t;
    ll m=(int)t.size();
    vector<ll> vl(m+1,0),vr(m+1,0);
    vector<string> s(n);
    rep(i,n) {
        cin >> s[i];
        int idx=0,ridx=m-1;
        rep(j,(int)s[i].size()) {
            if(idx<m&&s[i][j]==t[idx]) idx++;
        } 
        reverse(all(s[i]));
        rep(j,(int)s[i].size()) {
            if(ridx>=0&&s[i][j]==t[ridx]) ridx--;
        }
        vl[idx]++;
        vr[ridx+1]++;
    }
    ll ans=0;
    for(int i=0;i<=m;i++) {
        if(i) vr[i]+=vr[i-1];
        ans+=vl[i]*vr[i];
    }
    cout << ans << endl;
    return 0;
}