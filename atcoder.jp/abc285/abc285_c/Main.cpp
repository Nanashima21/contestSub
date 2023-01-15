#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    string s;
    cin >> s;
    reverse(all(s));
    ll ans=0;
    ll x=1;
    rep(i,(int)s.size()) {
        ans+=(s[i]-'A'+1)*x;
        x*=26;
    }
    cout << ans << endl;
    return 0;
}