#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n; ll a,b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    ll ans=INF;
    rep(i,n) {
        string str=s.substr(i)+s.substr(0,i);
        ll tot=a*i,cnt=0;
        rep(j,n) if(str[j]!=str[n-j-1]) cnt++;
        ans=min(ans,tot+cnt/2*b);
    }
    cout << ans << endl;
    return 0;
}