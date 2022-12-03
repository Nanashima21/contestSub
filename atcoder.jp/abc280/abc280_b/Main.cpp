#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    vector<ll> s(n),ans;
    rep(i,n) cin >> s[i];
    ans.push_back(s[0]);
    ll tot=s[0];
    for(int i=1;i<n;i++) {
        ans.push_back(s[i]-tot);
        tot=s[i];
    }
    rep(i,(int)ans.size()) {
        if(i) cout << " ";
        cout << ans[i];
    } cout << endl;
    return 0;
}