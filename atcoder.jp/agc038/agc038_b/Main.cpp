#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    set<ll> se;
    ll ans=n-k+1;
    ll idx=0,cnt=0;
    rep(i,n) {
        se.insert(p[i]);
        if(i&&p[i-1]>p[i]) idx=i;
        if(i>=k-1&&idx<=i-k+1) cnt++;
        else if(i>=k&&p[i]==*se.rbegin()&&p[i-k]==*se.begin()) ans--;
        if(i>=k) se.erase(p[i-k]);
    }
    cout << ans-max(0LL,cnt-1) << endl;
    return 0;
}